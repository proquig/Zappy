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

    fdclient = add_client(&server->fds, fd);
    player = init_player(fdclient, &server->param);
    server->players = add_player(server->players, player);
    if (server->param.c * tablen(server->param.n) < len_players(server->players))
        close_client(server, fdclient);
     else
        send_msg(server, fdclient, "BIENVENUE\n");
}

void 			start_server(t_server *server)
{
  int			  fd_max;
  struct timeval  tv;
  int             error;
    int res;

    res = 0;
  error = 1;
  server->players = NULL;
  while (error)
    {
        res++;
      tv.tv_sec = 0;
      tv.tv_usec = (1 / server->param.t * FREQUENCY);
      fd_max = set_fds(server);
      if (select(fd_max + 1, &server->fds.fds_read, &server->fds.fds_write, NULL, &tv) == -1)
      {
        error = 0;
        perror("select");
      }
	  handle_clients(server);
        if (res % 100000 == 0) {
            res = 0;
            put_random_ressource(server->map, server->param.x, server->param.y);
        }
    }
}

int			init_server(t_param *param, t_fds *fds)
{
  struct protoent 	*pe;
  struct sockaddr_in 	s_in;
  socklen_t		size;
  int 			fd;

  if (!(pe = getprotobyname("TCP"))
      || (fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  size = sizeof(s_in);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(param->p);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *) &s_in, size) == -1
      || listen(fd, MAX_FD) == -1)
    return (-1);
  fds->fd_type[fd] = FD_SERVER;
  fds->fct_read[fd] = server_read;
  fds->fct_write[fd] = NULL;
  return (0);
}
