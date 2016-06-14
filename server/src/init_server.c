//
// Created by cloquet on 14/06/16.
//

#include "server.h"

void 			server_read(t_env *e, int fd)
{
 // add_client(e, fd, clt);
  printf("New client\r\n");
}

int			init_server(t_param *param)
{
  t_env			env;
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
  env.fd_type[fd] = FD_SERVER;
  env.fct_read[fd] = server_read;
  env.fct_write[fd] = NULL;
  return (0);
}