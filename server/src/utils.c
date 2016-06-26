/*
** utils.c for zappy in /home/proqui_g/rendu/PSU_2015_zappy/server/src
** 
** Made by Guillaume PROQUIN
** Login   <proqui_g@epitech.net>
** 
** Started on  Tue Jun 14 09:50:48 2016 Guillaume PROQUIN
** Last update Sun Jun 26 11:53:19 2016 Guillaume PROQUIN
*/

#include "server.h"

void		error(const char *msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(0);
}

int		is_number(const char *str)
{
  return (!str[0] || (str[0] >= '0' && str[0] <= '9' && is_number(&str[1])));
}

int		is_delimiter(char c, const char *dels)
{
  int		i;

  i = -1;
  while (dels[++i] && dels[i] != c);
  return (dels[i] ? 1 : 0);
}

int		count_cmds(const char *line, const char *dels)
{
  int		i;
  int		count;

  count = 0;
  i = -1;
  while (line[++i])
    if (!is_delimiter(line[i], dels)				\
        && (is_delimiter(line[i + 1], dels) || !line[i + 1]))
      count++;
  return (count);
}

char		**get_cmds(const char *str, const char *dels)
{
  int		i;
  int		j;
  int		k;
  int		word_size;
  char		**tab;

  tab = malloc(sizeof(char*) * (count_cmds(str, dels) + 1));
  i = -1;
  while (is_delimiter(str[++i], dels));
  j = 0;
  while (str[i])
    {
      word_size = i - 1;
      while (str[++word_size] && !is_delimiter(str[word_size], dels));
      if (!tab || (tab[j] = malloc(sizeof(char) * (word_size - i + 1))) == NULL)
	return (NULL);
      k = 0;
      while (str[i] && !is_delimiter(str[i], dels))
	tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] && is_delimiter(str[i], dels))
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
