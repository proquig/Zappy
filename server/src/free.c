/*
** free.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Sun Jun 26 10:09:02 2016 Guillaume PROQUIN
** Last update Sun Jun 26 10:55:47 2016 Guillaume PROQUIN
*/

#include "server.h"

int	tablen(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
