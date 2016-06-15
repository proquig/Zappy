/*
** main.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Fri Jun 10 12:17:55 2016 Cloquet
** Last update Tue Jun 14 13:27:49 2016 Guillaume PROQUIN
*/

#include "player.h"
#include "server.h"

int		main(int ac, const char **av)
{
  t_param	param;
  t_env		env;

  /*
  //
  t_player *list;
  t_player *tmp;
  list = init_player(1);
  tmp = list;
  while (tmp)
  {
	printf("%d\n", tmp->fd);
	tmp = tmp->next;
  }
  printf("END STEP1\n");
  list = del_player(list, list);
  tmp = list;
  while (tmp)
  {
	printf("%d\n", tmp->fd);
	tmp = tmp->next;
  }
  printf("END STEP2\n");
  list = init_player(0);
  t_player *player1 = init_player(1);
  t_player *player2 = init_player(2);
  add_player(list, player1);
  add_player(list, player2);
  tmp = list;
  while (tmp)
  {
	printf("%d\n", tmp->fd);
	tmp = tmp->next;
  }
  printf("END STEP3\n");
  list = del_player(list, list);
  tmp = list;
  while (tmp)
  {
	printf("%d\n", tmp->fd);
	tmp = tmp->next;
  }
  printf("END STEP4\n");
  list = del_player(list, player1);
  tmp = list;
  while (tmp)
  {
	printf("%d\n", tmp->fd);
	tmp = tmp->next;
  }
  printf("END STEP5\n");
  list = del_player(list,player2);
  tmp = list;
  while (tmp)
  {
	printf("%d\n", tmp->fd);
	tmp = tmp->next;
  }
  printf("END STEP6\n");
  return (0);
   */
  //
  if (ac < 7)
    error("argv");
  init_params(&param);
  if (!set_params(av, &param))
    error("Wrong args");
  if (init_server(&param, &env) == -1)
    error("Server init failed");
  start_server(&env);
  return (0);
}
