//
// Created by cloquet on 17/06/16.
//

#include "server.h"

void		move_up(t_player *player, t_param *param, t_square **map)
{
  (void)map;
  player->y--;
  if (player->y < 0)
    player->y = param->y;
}

void		move_down(t_player *player, t_param *param, t_square **map)
{
  (void)map;
  player->y++;
  if (player->y < param->y)
    player->y = 0;
}

void		move_left(t_player *player, t_param *param, t_square **map)
{
  (void)map;
  player->x--;
  if (player->x < 0)
    player->x = param->x;
}

void		move_right(t_player *player, t_param *param, t_square **map)
{
  (void)map;
  player->x++;
  if (player->x < param->x)
    player->x = 0;
}


void		avance(char **tab, t_player *player, t_param *param, t_square **map)
{
  t_avance	avance1[] = {
	  {UP, &move_up},
	  {DOWN, &move_down},
	  {LEFT, &move_left},
	  {RIGHT, &move_right},
  };
  int 		i;

  i = -1;
  (void)tab;
  while (avance1[++i].ptr)
    if (avance1[i].str == player->dir)
      avance1[i].ptr(player, param, map);
  printf("YELLO\n");
  dprintf(player->fd, "ok\n");
}