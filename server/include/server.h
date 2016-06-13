/*
** server.h for  in /home/cloquet/PSU_2015_zappy/server/include
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:18:28 2016 Cloquet
** Last update Fri Jun 10 12:19:13 2016 Cloquet
*/

#ifndef _ZAPPY_SERVER_H_
# define _ZAPPY_SERVER_H_

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

/*
-p numero de port
-x largeur du Monde
-y hauteur du Monde
-n nom_de_equipe_1 nom_de_equipe_2 ...
-c nombre de clients par équipe autorisés au commencement du jeu
-t delai temporel d’execution des actions.
 */

typedef struct	s_param
{
  int		p;
  int		x;
  int 		y;
  char		**team;
  int		c;
  int		t;
}		t_param;

typedef struct	s_option
{
  char 		*options;
  void		(*f)(char *, t_param *);
}		t_option;

void		error(char *msg);
void		set_param(char **pString, t_param *param);
void		set_port(char *pString, t_param *param);
void		set_width(char *pString, t_param *param);
void		set_height(char *pString, t_param *param);
void		set_delay(char *pString, t_param *param);

#endif /* _ZAPPY_SERVER_H_ */
