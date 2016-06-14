/*
** server.h for  in /home/cloquet/PSU_2015_zappy/server/include
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:18:28 2016 Cloquet
** Last update Tue Jun 14 11:35:59 2016 Guillaume PROQUIN
*/

#ifndef		__ZAPPY_SERVER_H__
# define	__ZAPPY_SERVER_H__

#include	<stdlib.h>
#include	<stdio.h>
#include	<memory.h>
#include	<netdb.h>

# define MAX_FD 255

typedef void			(*fct)();

enum				FD {
  FD_FREE = 0,
  FD_CLIENT = 1,
  FD_SERVER = 2
};

typedef struct			s_param
{
  int		p;
  int		x;
  int 		y;
  int		c;
  int		t;
  char		**n;
}		t_param;

typedef struct	s_option
{
  char 		arg;
  void		*param;
  int		(*f)(char **, void *);
}		t_option;

typedef struct	s_env
{
  char		fd_type[MAX_FD];
  fct		fct_read[MAX_FD];
  fct		fct_write[MAX_FD];
}		t_env;

void		error(char *msg);
void		set_param(char **pString, t_param *param);
void		set_port(char *pString, t_param *param);
void		set_width(char *pString, t_param *param);
void		set_height(char *pString, t_param *param);
void		set_delay(char *pString, t_param *param);
int		init_server(t_param *param);

void		error(char *msg);
int		is_number(char *str);

void		init_params(t_param *params);
int		set_int_param(char **args, void *param);
int		set_char_param(char **args, void *param);
int		set_params(char **args, t_param *params);

#endif /* _ZAPPY_SERVER_H_ */
