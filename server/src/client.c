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
  // CHECK MAX FD IN CLIENTS
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

void			client_read(t_server *server, int fd)
{
  // TODO: buffer circulaire
  ssize_t		r;
  char			buf[4096];

  if ((r = read(fd, buf, 4096)) > 0)
  {
	buf[r] = 0;
	printf("Send by %d: %s\r\n", fd, buf);
	server->tab = get_cmds(buf, " \t\r\n");
	if (analyse_commande(server, search_player(server->players, fd)) == -1)
	  close_client(server, fd);
  }
  else
	close_client(server, fd);
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
  fds->fct_write[fd] = NULL;
  dprintf(fd, "BIENVENUE\n");
  return (fd);
}

void 		handle_clients(t_server *server)
{
  int 	i;
  i = -1;
  while (++i < MAX_FD)
	if (FD_ISSET(i, &server->fds.fds_read))
	  server->fds.fct_read[i](server, i);
}
