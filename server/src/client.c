//
// Created by proqui_g on 6/22/16.
//

#include "server.h"
#include "player.h"

int 	set_fds(t_server *server)
{
  int	fd_max;
  int	i;

  i = -1;
  FD_ZERO(&server->fds.fds_read);
  FD_ZERO(&server->fds.fds_write);
  while (++i < MAX_FD)
	if (server->fds.fd_type[i] != FD_FREE)
	{
	  FD_SET(i, &server->fds.fds_read);
	  FD_SET(i, &server->fds.fds_write);
	  fd_max = i;
	}
  return (fd_max);
}


void			close_client(t_server *server, int fd)
{
  printf("Connection closed on %i\n", fd);
  server->players = del_player(server->players, fd);
  close(fd);
  server->fds.fd_type[fd] = FD_FREE;
}

char            *cat_buff(char *str, char *buff)
{
  char          *ret;

  str = str ? str : "";
  buff = buff ? buff : "";
  if (!(ret = malloc(strlen(buff) + strlen(str) + 1)))
	return (NULL);
  ret[0] = 0;
  strcat(ret, str);
  strcat(ret, buff);
  if (strlen(str))
	free(str);
  return (ret);
}

void			client_read(t_server *server, int fd)
{
  int 			i;
  int 			j;
  char			buff[1024];
  ssize_t 		size;
  t_player		*player;

  // TODO: command ko
  // TODO: free
  i = -1;
  if (!(player = search_player(server->players, fd))
	|| (size = read(fd, buff, 1023)) <= 0)

  {
      close_client(server, fd);
      return;
  }
    buff[size] = 0;
  while (size && (i == - 1 || i != size))
  	{
	  j = i + 1;
	  while (++i < size && buff[i] && buff[i] != '\n');
	  if (buff[i])
	  {
		buff[i] = 0;
		player->cmd = cat_buff(player->cmd, &buff[j]);
		player->tab = get_cmds(player->cmd, " \t\r\n");
		if (analyse_commande(server, player) == -1)
		  close_client(server, fd);
		else
		{
		  free(player->cmd);
		  free_tab(player->tab);
		  player->cmd = NULL;
		  player->tab = NULL;
		}
	  }
	  else
	  {
		buff[i] = 0;
		player->cmd = cat_buff(player->cmd, &buff[j]);
	  }
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

int			add_client(t_fds *fds, int fd)
{
  struct sockaddr_in	client_sin;
  unsigned int 		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((fd = accept(fd, (struct sockaddr *) &client_sin, &client_sin_len)) == -1)
  {
	perror("accept");
	exit(0);
  }
  fds->fd_type[fd] = FD_CLIENT;
  fds->fct_read[fd] = client_read;
  fds->fct_write[fd] = client_write;
  dprintf(fd, "BIENVENUE\n");
  return (fd);
}

void 		handle_clients(t_server *server)
{
  int 	i;

  i = -1;
  while (++i < MAX_FD)
  {
	if (FD_ISSET(i, &server->fds.fds_read))
	  server->fds.fct_read[i](server, i);
	if (FD_ISSET(i, &server->fds.fds_write)
		&& server->fds.fd_type[i] != FD_SERVER
            && server->fds.fd_type[i] != FD_FREE)
	  	server->fds.fct_write[i](server, i);
  }
}
