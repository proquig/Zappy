//
// utils.cpp for  in /home/jacque_x/rendu/Tek2/PSU_2015_zappy/client/src
// 
// Made by jacque_x
// Login   <jacque_x@epitech.net>
// 
// Started on  Wed Jun 15 22:23:10 2016 jacque_x
// Last update Sun Jun 26 14:40:35 2016 jacque_x
//

#include "IA.hpp"

void	error(const char *msg)
{
  fprintf(stderr, "\033[31m%s\033[0m\n", msg);
  exit(0);
}

void	IA::print(std::string command, int i)
{
  std::cout << "\E[31;1mRECEIVED_" << i << " : " << command << "\E[m";
}

std::vector<std::string>	verif_params(char **av)
{
  std::vector<std::string> args;
  int	i;

  i = 1;
  while (i != 6)
    {
      if (strcmp(av[i], "-n") == 0 || strcmp(av[i], "-p") == 0 || strcmp(av[i], "-h") == 0)
	{
	  args.push_back(std::string(av[i]));
	  
	  args.push_back(std::string(av[i + 1]));
	}
      i++;
    }
  if (args[0] == args[2] || args[0] == args[4] || args[2] == args[4])
    error("Usage : -n [team_name] -p [port] -h [host]");
  verif2(args);
  return (args);
}

void	verif2(std::vector<std::string> args)
{
  unsigned int	i;
  int	x;

  x = 0;
  i = 0;
  while (i != args.size())
    {
      if (strcmp(args[i].c_str(), "-p") == 0)
	{
	  while (args[i + 1][x])
	    {
	      if (args[i + 1][x] < '0' || args[i + 1][x] > '9')
		error("Usage : -n [team_name] -p [port] -h [host]");
	      x++;
	    }
	}
      i++;
    }
}
