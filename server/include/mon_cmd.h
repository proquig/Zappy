/*
** mon_cmd.h for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 10:54:03 2016 Guillaume PROQUIN
** Last update Sun Jun 26 10:54:05 2016 Guillaume PROQUIN
*/

#ifndef   		__ZAPPY_SERVER_GRAPHIC_CMD_H__
# define  		__ZAPPY_SERVER_GRAPHIC_CMD_H__

# include		"server.h"

typedef struct	s_cmd
{
  const char 	*cmd;
  int 	nb_params;
  int 			(*fn)(t_server *server, t_player *player);
}				t_cmd;

int 	event_pgt(t_server *server, t_player *player);
int 	event_pdr(t_server *server, t_player *player);
int		event_ppo(t_server *server, t_player *player);
int		event_pnw(t_server *server, t_player *player);
int		event_pdi(t_server *server, t_player *player);

void 		notify(t_server *server, char *fn);
void	exec_graphic_cmd(t_server *server, t_player *player);
void		cmd_mon_welcome(t_server *server, t_player *player);

int 	cmd_mon_msz(t_server *server, t_player *player);
int 	cmd_mon_bct(t_server *server, t_player *player);
int 	cmd_mon_mct(t_server *server, t_player *player);
int 	cmd_mon_tna(t_server *server, t_player *player);
int 	cmd_mon_ppo(t_server *server, t_player *player);
int 	cmd_mon_plv(t_server *server, t_player *player);
int 	cmd_mon_pin(t_server *server, t_player *player);
int 	cmd_mon_sgt(t_server *server, t_player *player);
int 	cmd_mon_sst(t_server *server, t_player *player);

#endif
