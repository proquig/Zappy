/*
** init_server.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Wed Jun 15 10:48:49 2016 Cloquet
** Last update Wed Jun 15 10:48:53 2016 Cloquet
*/

#include "server.h"
#include "player.h"

t_player 		*closeclient(t_env *e, int fd, t_player *list)
{
  printf("Connection closed\n");
  list = del_player(list, fd);
  close(fd);
  e->fd_type[fd] = FD_FREE;
  return (list);
}

t_player		*client_read(t_env *e, int fd, t_player *list, t_param *param, t_square **map)
{
  ssize_t		r;
  char			buf[4096];

  if ((r = read(fd, buf, 4096)) > 0)
    {
      buf[r] = 0;
      printf("Send by %d: %s\r\n", fd, buf);
      if (analyse_commande(get_cmds(buf, " \t\r\n"), search_player(list, fd), param, map) == -1)
	    list = closeclient(e, fd, list);
    }
  else
   list = closeclient(e, fd, list);
  return (list);
}

int			add_client(t_env *e, int s)
{
  struct sockaddr_in	client_sin;
  unsigned int 		client_sin_len;
  int 			fd;

  client_sin_len = sizeof(client_sin);
  if ((fd = accept(s, (struct sockaddr *) &client_sin, &client_sin_len)) == -1)
    {
      perror("accept");
      exit(0);
    }
  e->fd_type[fd] = FD_CLIENT;
  e->fct_read[fd] = client_read;
  e->fct_write[fd] = NULL;
  dprintf(fd, "BIENVENUE\r\n");
  return (fd);
}

t_player		*server_read(t_env *e, int fd, t_player *list)
{
  int 			fdclient;

  fdclient = add_client(e, fd);
  list = add_player(list, init_player(fdclient));
  return (list);
}

int 			start_server(t_env *env, t_param *param, t_square **map)
{
  t_player		*root;
  int			i;
  fd_set		fd_read;
  int			fd_max;
  struct timeval	tv;

  root = NULL;
  while (1)
    {
      printf("%p\n", root); // DEBUG
      tv.tv_sec = 1;
      tv.tv_usec = (__suseconds_t)0.1;
      FD_ZERO(&fd_read);
      fd_max = 0;
      i = -1;
      while (++i < MAX_FD)
	if (env->fd_type[i] != FD_FREE)
	  {
	    FD_SET(i, &fd_read);
	    fd_max = i;
	  }
      if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
	perror("select");
      i = -1;
      while (++i < MAX_FD)
	if (FD_ISSET(i, &fd_read))
	  root = env->fct_read[i](env, i, root, param, map);
    }
}

int			init_server(t_param *param, t_env *env)
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
  env->fd_type[fd] = FD_SERVER;
  env->fct_read[fd] = server_read;
  env->fct_write[fd] = NULL;
  return (0);
}
