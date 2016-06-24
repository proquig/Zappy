//
// Created by cloque_b on 21/06/16.
//

#include "server.h"

int tablen(char **tab)
{
    int i;

    i = -1;
    while(tab[++i])
    ;
    return (i);
}

void free_tab(char **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}