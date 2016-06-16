/*
** map.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Thu Jun 16 10:31:00 2016 Guillaume PROQUIN
** Last update Thu Jun 16 10:31:26 2016 Guillaume PROQUIN
*/

#include "map.h"

void 			init_map(t_square ***map, unsigned int x, unsigned int y)
{
  int 			i;
  int 			j;
  int 			k;

  i = -1;
  while ((unsigned int)(++i) < y)
  {
    j = -1;
    while ((unsigned int)(++j) < x)
      {
	k = -1;
	while (++k < RES_SIZE)
	  map[y][x]->res.res[k] = 0;
	map[y][x]->player = NULL;
      }
  }
}

void 			put_random_ressource(t_square ***map, int size_x, int size_y)
{
  unsigned int	x;
  unsigned int	y;

  srand(0);
  x = rand() % size_x;
  y = rand() % size_y;
  map[y][x]->res.res[rand() % RES_SIZE]++;
}
