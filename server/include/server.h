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

# define			MAX_FD 1023
# define			GRAPHIC 900

# define			NB_ACTIONS 10
# define			FREQUENCY 1000000

typedef void		(*fct)(t_server *server, int fd);

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
//  char				**tab;
  t_square			**map;
  t_player			*players;
  t_param			param;
  t_fds				fds;
  struct timeval	*loop;
}					t_server;

typedef struct 		s_expulse
{
  enum Direction	dir;
  int 				pos;
}					t_expulse;

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

int 				time_is_lower(struct timeval *time1, struct timeval *time2);
int					action_is_waiting(struct timeval *time);
void				set_action_time(struct timeval *time, int value, int frequency);

int 				set_fds(t_server *server);
void				close_client(t_server *server, int fd);
void				client_read(t_server *server, int fd);
void				client_write(t_server *server, int fd);
int					add_client(t_fds *fds, int fd);
void				handle_clients(t_server *server);

void				free_tab(char **tab);


int     			incantation_is_possible(t_server *server, t_player *player);
int     			tell_to_players(t_player *root, t_player *t);

// TODO: define max actions
void				init_action(t_action *action);
void				init_actions(t_action actions[10]);
t_action			*find_free_action(t_action actions[10]);
t_action        	*get_current_action(t_action actions[10]);
void        		set_action(t_server *server, t_player *player, int time,
							   void (*fn)(t_server *, t_player *));

int     tell_ko_players(t_player *root, t_player *t);

#endif /* _ZAPPY_SERVER_H_ */
