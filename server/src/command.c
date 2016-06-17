//
// Created by cloquet on 14/06/16.
//

#include "server.h"

void right(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)param;
  (void)map;
  if (player->dir == UP)
    player->dir = RIGHT;
  if (player->dir == DOWN)
    player->dir = LEFT;
  if (player->dir == LEFT)
    player->dir = UP;
  if (player->dir == RIGHT)
    player->dir = DOWN;
}

void gauche(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)param;
  (void)map;
  if (player->dir == UP)
    player->dir = LEFT;
  if (player->dir == DOWN)
    player->dir = RIGHT;
  if (player->dir == LEFT)
    player->dir = DOWN;
  if (player->dir == RIGHT)
    player->dir = UP;
}

void voir(char **tab, t_player *player, t_param *param, t_square **map)
{
  int x;
  int y;

  y = -1;
  (void)tab;
  (void)param;
  printf("player=%i - %i\n", player->y, player->x);
  printf("in map=%i - %i\n", map[0][0].player->y, map[0][0].player->x);
  while (++y < param->y)
    {
      x = 0;
      while (x < param->x)
	{
	  if (map[y][x].player && map[y][x].player->fd == player->fd)
	    {
	      int i;

	      i = 0;
	      printf("PLOP\n");
	      dprintf(player->fd, "{ joueur");
	      while (map[y][x].res.res[i])
		  dprintf(player->fd, ", %i", map[y][x].res.res[i++]);
	      dprintf(player->fd, " }\n");
	    }
	  x++;
	}
    }

}

void inventaire(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void prend(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void pose(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void expulse(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void broadcast(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void incantation(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void forker(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void connect_nbr(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}

void die(char **tab, t_player *player, t_param *param, t_square **map)
{
  (void)tab;
  (void)player;
  (void)param;
  (void)map;
}
