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
#include			<sys/time.h>
#include			"common.h"

# define			MAX_FD 900
# define			GRAPHIC 900

typedef void		(*fct)();

typedef struct		s_server t_server;

enum				FD {
  FD_FREE = 0,
  FD_CLIENT = 1,
  FD_SERVER = 2
};

typedef struct		s_param
{
  int				p;
  unsigned int		x;
  unsigned int 		y;
  int				c;
  int				t;
  char				**n;
}					t_param;

typedef struct		s_option
{
  char 				arg;
  void				*param;
  int				(*f)(const char **, void *);
}					t_option;

typedef struct		s_fds
{
  char				fd_type[MAX_FD];
  fd_set			fds_read;
  fd_set			fds_write;
  fct				fct_read[MAX_FD];
  fct				fct_write[MAX_FD];
}					t_fds;

typedef struct		s_avance
{
  enum Direction 	str;
  void 				(*ptr)(t_server *server, t_player *player);
}					t_avance;

typedef struct		s_server
{
  char				**tab;
  t_square			**map;
  t_player			*players;
  t_param			param;
  t_fds				fds;
}					t_server;

typedef struct 		s_expulse
{
  enum Direction	dir;
  int 				pos;
}					t_expulse;

typedef struct		s_action
{
    int         	time;
    void 			(*f)(t_server *server, t_player *player);
    struct			s_action *next;
}               	t_action;

t_action    		*init_action(void (*fonction)(t_server *server, t_player *player),
                         int time);
t_action    		*add_action(t_action *list, t_action *new);

int					tablen(char **tab);
int					init_server(t_param *param, t_fds *fds);
void				error(const char *msg);
int					is_number(const char *str);
void				init_params(t_param *params);
int					set_int_param(const char **args, void *param);
int					set_char_param(const char **args, void *param);
int					set_params(const char **args, t_param *params);
int					start_server(t_server *server);
char				**get_cmds(const char *str, const char *dels);
int					analyse_commande(t_server *server, t_player *player);

void				set_action_time(struct timeval *time, int value, int frequency);
void				set_action_time(struct timeval *time, int value, int frequency);

int 				set_fds(t_server *server);
void				close_client(t_server *server, int fd);
void				client_read(t_server *server, int fd);
int					add_client(t_fds *fds, int fd);
void				handle_clients(t_server *server);

void free_tab(char **tab);

#endif /* _ZAPPY_SERVER_H_ */
