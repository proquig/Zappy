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

void			init_square(t_square *square, unsigned int x, unsigned int y)
{
  int 			i;

  i = -1;
  while (++i < RES_SIZE)
	square->res.res[i] = 0;
  square->player = NULL;
  square->x = x;
  square->y = y;
}

void 			init_map(t_square ***map,
						 unsigned int size_x, unsigned int size_y)
{
  int 			i;
  int 			j;

  i = -1;
  while ((unsigned int)(++i) < size_y)
  {
    j = -1;
    while ((unsigned int)(++j) < size_x)
	  init_square(map[size_y][size_x], size_x, size_y);
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

void			print_square_contents(t_square *square, int fd)
{
  int 			i;

  i = -1;
  dprintf(fd, "bct %u %u", square->x, square->y);
  while (++i < RES_SIZE)
	dprintf(fd, " %u", square->res.res[i]);
  dprintf(fd, "\n");
}

void			print_map_contents(t_square ***map, int fd,
								   unsigned int x, unsigned int y)
{
  int 			i;
  int 			j;

  i = -1;
  while ((unsigned int)(++i) < y)
  {
	j = -1;
	while ((unsigned int)(++j) < x)
	  print_square_contents(map[y][x], fd);
  }
}