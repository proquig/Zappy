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

# include	"player.h"

typedef struct	s_square
{
  t_ressources	res;
  t_player	*player;
}		t_square;

#endif
