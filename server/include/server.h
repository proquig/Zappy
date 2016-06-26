/*
** server.h for  in /home/cloquet/PSU_2015_zappy/server/include
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:18:28 2016 Cloquet
** Last update Sun Jun 26 23:18:01 2016 Guillaume PROQUIN
*/

#ifndef			__ZAPPY_SERVER_H__
# define		__ZAPPY_SERVER_H__

# define		_GNU_SOURCE
#include		<stdlib.h>
#include		<stdio.h>
#include		<memory.h>
#include		<netdb.h>
#include		<zconf.h>
#include		<sys/time.h>
#include		"common.h"

# define		MAX_FD 1023
# define		GRAPHIC 900

# define		NB_ACTIONS 10
# define		FREQUENCY 1000000

typedef void		(*fct)(t_server *server, int fd);

typedef struct		s_server t_server;

enum			FD {
  FD_FREE = 0,
  FD_CLIENT = 1,
  FD_SERVER = 2
};

typedef struct		s_param
{
  int			p;
  unsigned int		x;
  unsigned int 		y;
  int			c;
  int			t;
  char			**n;
}			t_param;

typedef struct		s_option
{
  char 			arg;
  void			*param;
  int			(*f)(const char **, void *);
}			t_option;

typedef struct		s_fds
{
  int 			fd;
  char			fd_type[MAX_FD];
  fd_set		fds_read;
  fd_set		fds_write;
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
}			t_fds;

typedef struct		s_avance
{
  enum Direction 	str;
  void 			(*ptr)(t_server *server, t_player *player);
}			t_avance;

typedef struct		s_server
{
  t_square		**map;
  t_player		*players;
  t_param		param;
  t_fds			fds;
  t_eggs		*eggs;
  struct timeval	loop;
}			t_server;

typedef struct 		s_expulse
{
  enum Direction	dir;
  int 			pos;
}			t_expulse;

void			init_action(t_action *action);
void			init_actions(t_action actions[10]);
t_action		*find_free_action(t_action actions[10]);
t_action        	*get_current_action(t_action actions[10]);
void        		set_action(t_server *server, t_player *player, int time,
							   void (*fn)(t_server *, t_player *));

void			move_up(t_server *server, t_player *player);
void			move_down(t_server *server, t_player *player);
void			move_left(t_server *server, t_player *player);
void			move_right(t_server *server, t_player *player);
void			avance(t_server *server, t_player *player);

int			tablen(char **tab);
int			init_server(t_param *param, t_fds *fds);

void 			send_msg(t_server *server, int fd, char *fmt, ...);
void			error(const char *msg);
int			is_number(const char *str);
int			count_cmds(const char *line, const char *dels);
char			**get_cmds(const char *str, const char *dels);

int			analyse_commande(t_server *server, t_player *player);

void			init_params(t_param *params);
int			set_int_param(const char **args, void *param);
int			set_char_param(const char **args, void *param);
int			set_params(const char **args, t_param *params);
void			start_server(t_server *server);

int 			time_is_lower(struct timeval *time1, struct timeval *time2);
int			action_is_waiting(struct timeval *time);
void			set_action_time(struct timeval *time, int value, int frequency);

int 			set_fds(t_server *server);
void			close_client(t_server *server, int fd, char *msg);
void			client_read(t_server *server, int fd);
void			client_write(t_server *server, int fd);
int			add_client(t_server *server, int fd);
void			handle_clients(t_server *server);

void			free_tab(char **tab);
void			free_cmds(t_player *player);
char			*cat_buff(char *str, char *buff);

int			check_incantation(t_server *server, t_player *player);
int     		incantation_is_possible(t_server *server, t_player *player);
int     		tell_to_players(t_server *server, t_player *t);
int     		tell_ko_players(t_server *server, t_player *t);

int             	server_is_running(int check);
void            	handle_signal(int signal);
void            	server_shutdown(t_server *server, char *msg);

int			get_team_max(t_player *root, int id, t_param param);
int			set_team(t_server *server, t_player *player);
void			update_team(t_player *root, int id);

void			cmd_welcome(t_server *server, t_player *player);
void 			init_player_res(t_player *player);
int			they_are_eggs(t_server *server);
t_player		*init_player_from_eggs(int fd, t_eggs *egg);
t_eggs			*init_eggs(unsigned int x, unsigned int y, t_team team);
t_eggs			*add_egg(t_eggs *list, t_eggs *player);

#endif      /* _ZAPPY_SERVER_H_ */
