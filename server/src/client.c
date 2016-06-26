/*
** client.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 09:54:39 2016 Guillaume PROQUIN
** Last update Sun Jun 26 23:18:55 2016 Guillaume PROQUIN
*/

#include "server.h"
#include "player.h"
#include "mon_cmd.h"
#include "map.h"

void		close_client(t_server *server, int fd, char *msg)
{
  if (!fd || fd == -1)
    return ;
  if (msg)
	send_msg(server, fd, msg);
  search_player(server->players, fd)->notify = 1;
  notify(server, "pdi");
  search_player(server->players, fd)->notify = 0;
  printf("Connection closed on %i\n", fd);
  server->players = del_player(server->players, fd);
  FD_CLR(fd, &server->fds.fds_read);
  FD_CLR(fd, &server->fds.fds_write);
  close(fd);
  server->fds.fd_type[fd] = FD_FREE;
}

void		client_read(t_server *server, int fd)
{
  int 		i;
  int 		j;
  int		check;
  char		buff[64];
  ssize_t 	size;
  t_player	*player;

  size = -1;
  i = -1;
  if (!(player = search_player(server->players, fd))
      || (size = read(fd, buff, 63)) <= 0)
    close_client(server, fd, NULL);
  buff[size] = 0;
  while (size > 0 && (i == - 1 || i != size))
    {
      j = i + 1;
      while (++i < size && buff[i] && buff[i] != '\n');
      check = buff[i] ? 1 : 0;
      buff[i] = 0;
      player->cmd = cat_buff(player->cmd, &buff[j]);
      if (check && analyse_commande(server, player) == -1)
	close_client(server, fd, NULL);
      if (check)
	free_cmds(player);
    }
}

void 			client_write(t_server *server, int fd)
{
  t_player		*player;
  int 			i;

  i = -1;
  if ((player = search_player(server->players, fd)))
    while (++i < NB_ACTIONS)
      if (player->actions[i].f && !action_is_waiting(&player->actions[i].time))
	{
	  player->actions[i].exec = 1;
	  player->actions[i].f(server, player);
	  free_tab(player->actions[i].cmd);
	  init_action(&player->actions[i]);
	}
}

int			add_client(t_server *server, int fd)
{
  struct sockaddr_in	client_sin;
  unsigned int 		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((fd = accept(fd, (struct sockaddr *) &client_sin, &client_sin_len)) == -1)
    server_shutdown(server, "accept failed\n");
  server->fds.fd_type[fd] = FD_CLIENT;
  server->fds.fct_read[fd] = client_read;
  server->fds.fct_write[fd] = client_write;
  return (fd);
}

void			handle_clients(t_server *server)
{
  int			i;
  t_player		*player;

  i = -1;
  player = server->players;
  while (++i < MAX_FD)
    if (FD_ISSET(i, &server->fds.fds_read))
      server->fds.fct_read[i](server, i);
  if (!action_is_waiting(&server->loop))
    {
      put_food_ressource(server, server->param.x, server->param.y);
      set_action_time(&server->loop, 1, server->param.t);
      while (player)
	{
	  player->res.res[FOOD] -= (player->teams.id != -1
				    && player->teams.id != GRAPHIC);
	  if (player->fd != -1 && player->res.res[FOOD] <= 0)
	    close_client(server, player->fd, "mort\n");
	  if (player->fd != -1 && FD_ISSET(player->fd, &server->fds.fds_write)
	      && server->fds.fd_type[player->fd] != FD_FREE)
	    server->fds.fct_write[player->fd](server, player->fd);
	  player = player->next;
	}
    }
}
