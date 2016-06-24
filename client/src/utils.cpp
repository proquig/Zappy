//
// utils.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Wed Jun 15 22:23:10 2016 jacque_x
// Last update Wed Jun 15 22:33:05 2016 jacque_x
//

#include "IA.hpp"

void            error(const char *msg)
{
  fprintf(stderr, "\033[31m%s\033[0m\n", msg);
  exit(0);
}

void    IA::print(std::string command, int i)
{
  std::cout << "\E[31;1mRECEIVED_" << i << " : " << command << "\E[m";
}

void	verif_params(char **av)
{
  int	i;

  i = 0;
  if (av[1] == NULL || av[2] == NULL)
    error("Wrong params");
  while (av[2][i])
    {
      if (av[2][i] < '0' || av[2][i] > '9')
	error("Wrong params");
      i++;
    }
}
