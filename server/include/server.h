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
#include <netdb.h>

# define MAX_FD 255

typedef void			(*fct)();

enum				FD {
  FD_FREE = 0,
  FD_CLIENT = 1,
  FD_SERVER = 2
};

typedef struct			s_param
{
  uint16_t			p;
  int				x;
  int 				y;
  char				**team;
  int				c;
  int				t;
}				t_param;

typedef struct			s_option
{
  char 				*options;
  void				(*f)(char *, t_param *);
}				t_option;

typedef struct			s_env
{
  char				fd_type[MAX_FD];
  fct				fct_read[MAX_FD];
  fct				fct_write[MAX_FD];
}				t_env;

void				error(char *msg);
void				set_param(char **pString, t_param *param);
void				set_port(char *pString, t_param *param);
void				set_width(char *pString, t_param *param);
void				set_height(char *pString, t_param *param);
void				set_delay(char *pString, t_param *param);
int				init_server(t_param *param);

#endif /* _ZAPPY_SERVER_H_ */
