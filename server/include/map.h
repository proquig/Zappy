/*
** map.h for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Thu Jun 16 10:31:52 2016 Guillaume PROQUIN
** Last update Thu Jun 16 10:32:24 2016 Guillaume PROQUIN
*/

#ifndef   	__ZAPPY_SERVER_MAP_H__
# define  	__ZAPPY_SERVER_MAP_H__

# include	<stdio.h>
# include	"player.h"

typedef struct	s_square
{
  unsigned int	x;
  unsigned int	y;
  t_ressources	res;
  t_player		*player;
}		t_square;

void		init_square(t_square *square, unsigned int x, unsigned int y);
void		init_map(t_square ***map, unsigned int x, unsigned int y);
void		put_random_ressource(t_square ***map, int size_x, int size_y);
void		print_square_contents(t_square *square, int fd);
void		print_map_contents(t_square ***map, int fd, unsigned int x, unsigned int y);

#endif
