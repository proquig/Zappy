/*
** map.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Thu Jun 16 10:31:00 2016 Guillaume PROQUIN
** Last update Sun Jun 26 23:16:23 2016 Guillaume PROQUIN
*/

#include <time.h>
#include "mon_cmd.h"
#include "server.h"

void			init_square(t_square *square, unsigned int x,
				    unsigned int y, unsigned int size[2])
{
  int 			i;

  i = -1;
  while (++i < RES_SIZE)
  {
	square->res.res[i] = 0;
	square->res.notify[i] = 0;
  }
  square->players = NULL;
  square->x = x;
  square->y = y;
  square->size_x = size[0];
  square->size_y = size[1];
}

t_square		**create_map(unsigned int size_x, unsigned int size_y)
{
  int 			i;
  int 			j;
  unsigned int		size[2] = {
    size_x, size_y
  };
  t_square		**map;

  map = malloc(size_y * sizeof(t_square*));
  i = -1;
  while ((unsigned int)(++i) < size_y)
    {
      if (!map || !(map[i] = malloc(size_x * sizeof(t_square))))
	return (NULL);
      j = -1;
      while ((unsigned int)(++j) < size_x)
	init_square(&map[i][j], (unsigned int) j, (unsigned int) i, size);
    }
  return (map);
}

void 			put_random_ressource(t_square **map, int size_x, int size_y)
{
  unsigned int		x;
  unsigned int		y;

  x = rand() % size_x;
  y = rand() % size_y;
  map[y][x].res.res[rand() % RES_SIZE]++;
}

void 			put_food_ressource(t_server *server, int size_x, int size_y)
{
  t_player      *player;
  unsigned int	x;
  unsigned int	y;

  if (!(rand() % 42))
  {
	x = rand() % size_x;
	y = rand() % size_y;
	server->map[y][x].res.res[FOOD]++;
	player = server->players;
	while (player && player->teams.id != GRAPHIC && (player = player->next));
	if (player && player->fd != -1 && player->teams.id == GRAPHIC)
	{
	  player->param[0] = x;
	  player->param[1] = y;
	  cmd_mon_bct(server, player);
	  player->param[0] = -1;
	  player->param[1] = -1;
	}
  }
}
