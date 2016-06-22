//
// Created by proqui_g on 6/22/16.
//

int 	set_fds(t_server *server)
{
  int	fd_max;
  int	i;

  i = -1;
  while (++i < MAX_FD)
	if (server->env.fd_type[i] != FD_FREE)
	{
	  FD_SET(i, &fd_read);
	  fd_max = i;
	}
  return (fd_max);
}