/*
** server.h for  in /home/cloquet/PSU_2015_zappy/server/include
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:18:28 2016 Cloquet
** Last update Tue Jun 14 11:35:59 2016 Guillaume PROQUIN
*/

#ifndef				__ZAPPY_SERVER_H__
# define			__ZAPPY_SERVER_H__

#include			<stdlib.h>
#include			<stdio.h>
#include			<memory.h>
#include			<netdb.h>
#include			<zconf.h>
#include			"common.h"

# define			MAX_FD 255
# define			GRAPHIC 900

typedef void		(*fct)();

typedef struct		s_server t_server;

enum				FD {
  FD_FREE = 0,
  FD_CLIENT = 1,
  FD_SERVER = 2
};

typedef struct			s_param
{
  int				p;
  unsigned int		x;
  unsigned int 		y;
  int				c;
  int				t;
  char				**n;
}				t_param;

typedef struct			s_option
{
  char 				arg;
  void				*param;
  int				(*f)(const char **, void *);
}				t_option;

typedef struct			s_env
{
  char				fd_type[MAX_FD];
  fct				fct_read[MAX_FD];
  fct				fct_write[MAX_FD];
}				t_env;

typedef struct			s_avance
{
  enum Direction 		str;
  void 					(*ptr)(t_server *server, t_player *player);
}						t_avance;

typedef struct          s_server
{
  char                  **tab;
  t_square              **map;
  t_player              *players;
  t_param               param;
  t_env					env;
}                       t_server;

typedef struct 		s_expulse
{
  enum Direction	dir;
  int 			pos;
}			t_expulse;

int				        init_server(t_param *param, t_env *env);
void                    error(const char *msg);
int                     is_number(const char *str);
void                    init_params(t_param *params);
int                     set_int_param(const char **args, void *param);
int                     set_char_param(const char **args, void *param);
int                     set_params(const char **args, t_param *params);
int                     start_server(t_server *server);
char                    **get_cmds(const char *str, const char *dels);
int                     analyse_commande(t_server *server, t_player *player);

#endif /* _ZAPPY_SERVER_H_ */
