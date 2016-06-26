/*
** client.h for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 10:53:51 2016 Guillaume PROQUIN
** Last update Sun Jun 26 10:53:52 2016 Guillaume PROQUIN
*/

#ifndef		__ZAPPY_SERVER_CLIENT_H__
# define	__ZAPPY_SERVER_CLIENT_H__

# include	"server.h"

int			set_fds(t_server *server);
void		close_client(t_server *server, int fd, char *msg);
void		client_read(t_server *server, int fd);
void 		client_write(t_server *server, int fd);
int			add_client(t_server *server, int fd);
void 		handle_clients(t_server *server);

#endif
