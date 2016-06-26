/*
** mon_cmd_map.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 11:25:50 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:28:50 2016 Guillaume PROQUIN
*/

#include "mon_cmd.h"

int		cmd_mon_msz(t_server *server, t_player *player)
{
  send_msg(server, player->fd, "msz %u %u\n", server->param.x, server->param.y);
  return (1);
}

int		cmd_mon_bct(t_server *server, t_player *player)
{
  unsigned int	x;
  unsigned int	y;
  int 		i;

  x = player->param[0] != -1 ? (unsigned int)player->param[0]
							 : (unsigned int)strtoul(player->tab[1], NULL, 10);
  y = player->param[1] != -1 ? (unsigned int)player->param[1]
							 : (unsigned int)strtoul(player->tab[2], NULL, 10);
  if (x >= server->param.x
      || y >= server->param.y)
    return (0);

  i = -1;
  send_msg(server, player->fd, "bct %u %u", x, y);
  while (++i < RES_SIZE)
    send_msg(server, player->fd, " %u", server->map[y][x].res.res[i]);
  send_msg(server, player->fd, "\n");
  return (1);
}

int		cmd_mon_mct(t_server *server, t_player *player)
{
  int 		i;
  int 		j;

  i = -1;
  while ((unsigned int)(++i) < server->map[0][0].size_y)
    {
      j = -1;
      while ((unsigned int)(++j) < server->map[0][0].size_x)
	{
	  player->param[0] = j;
	  player->param[1] = i;
	  cmd_mon_bct(server, player);
	}
    }
  player->param[0] = -1;
  player->param[1] = -1;
  return (1);
}
