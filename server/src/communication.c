/*
** communication.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:42:11 2016 Guillaume PROQUIN
** Last update Sun Jun 26 23:17:15 2016 Guillaume PROQUIN
*/

#include "server.h"

void 		send_msg(t_server *server, int fd, char *fmt, ...)
{
  va_list 	ap;
  char 		*str;

  va_start(ap, fmt);
  vasprintf(&str, fmt, ap);
  if (fd && fd != -1 && write(fd, str, strlen(str)) != (int)strlen(str))
	close_client(server, fd, NULL);
  free(str);
}

int		set_fds(t_server *server)
{
  int		fd_max;
  int		i;

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

char		*cat_buff(char *str, char *buff)
{
  char		*ret;

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

int		tell_to_players(t_server *server, t_player *t)
{
  t_player	*tmp;
  int		i;

  tmp = server->players;
  i = 0;
  while (tmp)
    {
      if (tmp->x == t->x && tmp->y == t->y && tmp->lvl == t->lvl) {
            send_msg(server, t->fd, "elevation en cours\n");
      }
      tmp = tmp->next;
    }
  return (i);
}

int		tell_ko_players(t_server *server, t_player *player)
{
  t_player	*tmp;
  int		i;

  tmp = server->players;
  i = 0;
  while (tmp)
    {
      if (tmp->x == player->x && tmp->y == player->y
	  && tmp->lvl == player->lvl)
	send_msg(server, player->fd, "ko\n");
      tmp = tmp->next;
    }
  return (i);
}
