//
// Created by cloquet on 14/06/16.
//

#include "server.h"

void 	create_map(t_param param)
{
  int 	i;
  int 	j;
  char ***map;

  i = -1;
  j = 0;
  if ((map = malloc(sizeof(char **) * param.y +1 )) == NULL ||
	    (map[i] = malloc(sizeof(char *) * param.x + 1)))
    error("Malloc Failed");
  while (++i < param.y)
    {
      map[i] = malloc(sizeof(char *) * param.x + 1);
      while (j < param.x)
	{
	  j++;
	}
    }
}