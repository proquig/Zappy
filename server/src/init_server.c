/*
** init_server.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Tue Jun 14 11:03:24 2016 Cloquet
** Last update Tue Jun 14 11:04:40 2016 Cloquet
*/


#include "server.h"

void			client_read(t_env *e, int fd)
{
  int			r;
  char			buf[4096];

  if ((r = read(fd, buf, 4096)) > 0)
    {
      buf[r] = 0;
      printf("Send by %d: %s\n", fd, buf);
    }
  else
    {
      printf("Connection closed\n");
      close(fd);
      e->fd_type[fd] = FD_FREE;
    }
}

void			add_client(t_env *e, int s)
{
  struct sockaddr_in	client_sin;
  unsigned int 		client_sin_len;
  int 			fd;

  client_sin_len = sizeof(client_sin);
  if ((fd = accept(s, (struct sockaddr *) &client_sin, &client_sin_len)) == -1)
    exit(0);
  e->fd_type[fd] = FD_CLIENT;
  e->fct_read[fd] = client_read;
  e->fct_write[fd] = NULL;
  dprintf(fd, "Welcome to Trantor\r\n");
}

void 			server_read(t_env *e, int fd)
{
  add_client(e, fd);
  printf("New client\r\n");
}

int 			start_server(t_env *e)
{
  int			i;
  fd_set		fd_read;
  int			fd_max;
  struct timeval	tv;

  while (1)
    {
      tv.tv_sec = 1;
      tv.tv_usec = (__suseconds_t)0.1;
      FD_ZERO(&fd_read);
      fd_max = 0;
      i = -1;
      while (++i < MAX_FD)
	if (e->fd_type[i] != FD_FREE)
	  {
	    FD_SET(i, &fd_read);
	    fd_max = i;
	  }
      if (select(fd_max + 1, &fd_read, NULL, NULL, &tv) == -1)
	perror("select");
      for (i = 0; i < MAX_FD; i++)
	if (FD_ISSET(i, &fd_read))
	  e->fct_read[i](e, i);
      printf("waiting...\n");
    }
}

int			init_server(t_param *param, t_env *env)
{
  struct protoent 	*pe;
  struct sockaddr_in 	s_in;
  socklen_t		size;
  int 			fd;

  if (!(pe = getprotobyname("TCP")))
    return (-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  size = sizeof(s_in);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(param->p);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (const struct sockaddr *) &s_in, size) == -1)
    return (-1);
  if (listen(fd, MAX_FD) == -1)
    return (-1);
  env->fd_type[fd] = FD_SERVER;
  env->fct_read[fd] = server_read;
  env->fct_write[fd] = NULL;
  return (0);
}
