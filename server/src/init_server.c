/*
** init_server.c for  in /home/cloquet/PSU_2015_zappy/server/src
** 
** Made by Cloquet
** Login   <cloquet@epitech.net>
** 
** Started on  Wed Jun 15 10:48:49 2016 Cloquet
** Last update Mon Jun 20 11:07:32 2016 jacque_x
*/

#include "server.h"
#include "player.h"

void close_client(t_server *server, int fd) {
    printf("Connection closed on %i\n", fd);
    server->players = del_player(server->players, fd);
    close(fd);
    server->env.fd_type[fd] = FD_FREE;
}

void client_read(t_server *server, int fd) {
    // TODO: buffer circulaire
    ssize_t r;
    char buf[4096];

    if ((r = read(fd, buf, 4096)) > 0) {
        buf[r] = 0;
        printf("Send by %d: %s\r\n", fd, buf);
        server->tab = get_cmds(buf, " \t\r\n");
        if (analyse_commande(server, search_player(server->players, fd)) == -1)
            close_client(server, fd);
    }
    else
        close_client(server, fd);
}

void client_write(t_server *server, int fd)
{
    t_player *tmp;
    tmp = server->players;

    (void)fd;
    while (tmp)
    {
        dprintf(tmp->fd, "%s\n", tmp->buffer);
        tmp = tmp->next;
    }
}

int add_client(t_env *env, int fd) {
    struct sockaddr_in client_sin;
    unsigned int client_sin_len;

    client_sin_len = sizeof(client_sin);
    if ((fd = accept(fd, (struct sockaddr *) &client_sin, &client_sin_len)) == -1) {
        perror("accept");
        exit(0);
    }
    env->fd_type[fd] = FD_CLIENT;
    env->fct_read[fd] = client_read;
    env->fct_write[fd] = client_write;
    dprintf(fd, "BIENVENUE\n");
    return (fd);
}

void server_read(t_server *server, int fd)
{
    int fdclient;

    fdclient = add_client(&server->env, fd);
    server->players = add_player(server->players, init_player(fdclient));
}

int set_fdset(t_server *server, fd_set *fd_read, fd_set *fd_write)
{
    int i;
    int fd_max;

    FD_ZERO(fd_read);
    FD_ZERO(fd_write);
    fd_max = 0;
    i = -1;
    while (++i < (server->param.c * tablen(server->param.n)))
        if (server->env.fd_type[i] != FD_FREE)
        {
            FD_SET(i, fd_read);
            FD_SET(i, fd_write);
            fd_max = i;
        }
    return (fd_max);
}

int start_server(t_server *server) {
    int i;
    fd_set fd_read;
    fd_set fd_write;
    int fd_max;
    struct timeval tv;

    server->players = NULL;
    while (1)
    {
        tv.tv_sec = 0;
        tv.tv_usec = (int) (1.0 / (double) server->param.t * 1000000);
        fd_max = set_fdset(server, &fd_read, &fd_write);
        if (select(fd_max + 1, &fd_read, &fd_write, NULL, &tv) == -1)
            perror("select");
        i = -1;
        while (++i < (server->param.c * tablen(server->param.n)))
            if (FD_ISSET(i, &fd_read))
                server->env.fct_read[i](server, i);

  //        server->env.fct_write[i](server, i);
    }
}

int init_server(t_param *param, t_env *env) {
    struct protoent *pe;
    struct sockaddr_in s_in;
    socklen_t size;
    int fd;

    if (!(pe = getprotobyname("TCP"))
        || (fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
        return (-1);
    size = sizeof(s_in);
    s_in.sin_family = AF_INET;
    s_in.sin_port = htons(param->p);
    s_in.sin_addr.s_addr = INADDR_ANY;
    if (bind(fd, (const struct sockaddr *) &s_in, size) == -1
        || listen(fd, MAX_FD) == -1)
        return (-1);
    env->fd_type[fd] = FD_SERVER;
    env->fct_read[fd] = server_read;
    env->fct_write[fd] = NULL;
    return (0);
}
