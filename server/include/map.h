/*
** map.h for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Thu Jun 16 10:31:52 2016 Guillaume PROQUIN
** Last update Sun Jun 26 10:52:51 2016 Guillaume PROQUIN
*/

#ifndef   	__ZAPPY_SERVER_MAP_H__
# define  	__ZAPPY_SERVER_MAP_H__

# include	<stdio.h>
# include	"common.h"

void		init_square(t_square *square, unsigned int x, unsigned int y);
t_square	**create_map(unsigned int x, unsigned int y);
void 		put_food_ressource(t_server *server, int size_x, int size_y);
void		put_random_ressource(t_square **map, int size_x, int size_y);
void		print_square_contents(t_server *server, t_player *player,
				      t_square *square);
void		print_map_contents(t_server *server, t_player *player);

#endif
