/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** exec
*/

#include "include.h"

int check_exec_error(fd_t **fd_info, vector_t fd, shell_t *s, char *path)
{
    dup2((*fd_info)->actual_in_out->x, fd.x);
    dup2((*fd_info)->actual_in_out->y, fd.y);
    (*fd_info)->actual_in_out = &fd;
    if (execve(s->tab[0], s->tab, s->env) == -1 \
    && access(s->tab[0], X_OK) == 0) {
        my_putstr(strcat(s->tab[0], "Permission denied.\n"));
        return (-1);
    }
    else if (execve(path, s->tab, s->env) == -1) {
        my_putstr(strcat(s->tab[0], ": Command not found.\n"));
        return (-1);
    }
    return (0);
}

char *get_valid_path(char *str, char **tab)
{
    char **path = my_str_to_word_array(str, ':');
    int i = 0;

    for (; path[i]; i++) {
        path[i] =  my_strcat1(path[i], "/");
        path[i] =  my_strcat1(path[i], tab[0]);
        if (access(path[i], F_OK) == 0) break;
        else path[i] = NULL;
    }
    return (path[i]);
}

int exec(shell_t *s, linked_t *list, fd_t *fd_info, vector_t fd)
{
    pid_t pidf = 0;
    int status;
    linked_t *node = find_node(list, "PATH", 4);
    char *path = get_valid_path(node->str, s->tab);

    pidf = fork();
    if (pidf == 0) {
        if (check_exec_error(&fd_info, fd, s, path) != 0)
            return (1);
    } else {
        wait(&status);
        kill(pidf, status);
        sig(status);
    }
    dup2(fd_info->actual_in_out->x, fd_info->std_in_out->x);
    dup2(fd_info->actual_in_out->y, fd_info->std_in_out->y);
    fd_info->actual_in_out->x = fd_info->std_in_out->x;
    fd_info->actual_in_out->y = fd_info->std_in_out->y;
    return (0);
}
