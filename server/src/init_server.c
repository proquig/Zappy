/*
** init_server.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Wed Jun 15 10:48:49 2016 Cloquet
** Last update Mon Jun 20 11:07:32 2016 jacque_x
*/

#include "server.h"
#include "player.h"

void			server_read(t_server *server, int fd)
{
    int fdclient;
    t_player    *player;

    fdclient = add_client(server, fd);
    player = init_player(fdclient, &server->param);
    server->players = add_player(server->players, player);
    if (server->param.c * tablen(server->param.n) < len_players(server->players))
        close_client(server, fdclient, NULL);
     else
        send_msg(server, fdclient, "BIENVENUE\n");
}

int             server_is_running(int check)
{
  static int	is_running = 1;

  if (!check)
    is_running = 0;
  return (is_running);
}

void            handle_signal(int signal)
{
  server_is_running(0);
}

void            server_shutdown(t_server *server, char *msg)
{
  t_player      *player;
  t_player      *tmp;
  int           i;

  if (msg)
    printf("%s\n", msg);
  shutdown(server->fds.fd, SHUT_RDWR);
  player = server->players;
  while (player)
  {
    i = -1;
    while (++i < 10)
      if (player->actions[i].cmd)
        free_tab(player->actions[i].cmd);
    if (player->cmd)
      free(player->cmd);
    if (player->tab)
      free_tab(player->tab);
    tmp = player;
    player = player->next;
    free(tmp);
  }
  exit(0);
}

void 			start_server(t_server *server)
{
  int			  fd_max;
  struct timeval  tv;

  server->players = NULL;
  server->loop.tv_sec = 0;
  server->loop.tv_usec = 0;
    int res = 0;
  while (server_is_running(1))
  {
      res++;
	  tv.tv_sec = 0;
      tv.tv_usec = (int)(1.0 / (double)server->param.t * FREQUENCY);
      fd_max = set_fds(server);
      if (select(fd_max + 1, &server->fds.fds_read, &server->fds.fds_write, NULL, &tv) == -1)
        server_shutdown(server, "select");
	  handle_clients(server);
      if (res % 100000 == 0) {
          res = 0;
          put_food_ressource(server->map, server->param.x, server->param.y);
      }
  }
  server_shutdown(server, NULL);
}

int			init_server(t_param *param, t_fds *fds)
{
  struct protoent *pe;
  struct sockaddr_in s_in;
  socklen_t size;
  int fd;

  if (!(pe = getprotobyname("TCP")) || (fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
	return (-1);
  size = sizeof(s_in);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(param->p);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *) &s_in, size) == -1 || listen(fd, MAX_FD) == -1)
	return (-1);
  fds->fd = fd;
  //WARNING RESET SERVER
  fds->fd_type[fd] = FD_SERVER;
  fds->fct_read[fd] = server_read;
  fds->fct_write[fd] = NULL;
  return (0);
}