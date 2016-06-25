//
// Created by proqui_g on 6/22/16.
//

#ifndef		__ZAPPY_SERVER_CLIENT_H__
# define	__ZAPPY_SERVER_CLIENT_H__

# include	"server.h"

int			set_fds(t_server *server);
void		close_client(t_server *server, int fd);
void		client_read(t_server *server, int fd);
void 		client_write(t_server *server, int fd);
int			add_client(t_server *server, int fd);
void 		handle_clients(t_server *server);

#endif
