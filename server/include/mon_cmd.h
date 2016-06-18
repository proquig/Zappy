//
// Created by proqui_g on 6/18/16.
//

#ifndef   		__ZAPPY_SERVER_GRAPHIC_CMD_H__
# define  		__ZAPPY_SERVER_GRAPHIC_CMD_H__

# include		"server.h"

typedef struct	s_cmd
{
  const char 	*cmd;
  int 	nb_params;
  int 			(*fn)(t_server *server, t_player *player);
}				t_cmd;

void	exec_graphic_cmd(t_server *server, t_player *player);

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
