/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** env_manage.c
*/

#include "include.h"

int check_env_args(shell_t *shell)
{
    if (shell->input_length > 3) {
        printf("setenv: Too many arguments.\n");
        return (1);
    }
    if (shell->input_length < 2) {
        do_env(shell, NULL);
        return (1);
    }
    if ((shell->tab[1][0] < 65 || shell->tab[1][0] > 90) && \
    (shell->tab[1][0] < 97 || shell->tab[1][0] > 122)) {
        printf("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    return (0);
}

void change_env_line(shell_t *shell, char *name, char *line)
{
    env_t *tmp = shell->list_env;

    for (; tmp; tmp = tmp->next) {
        if (tmp->name == NULL)
            tmp = tmp->next;
        if (my_strcmp(name, tmp->name) == 0) {
            free(tmp->line);
            tmp->line = malloc(sizeof(char) * 255);
            my_strcpy_tree(tmp->line, line);
            convert_env_in_tab(shell);
            return;
        }
    }
}

char *create_env_line(shell_t *shell)
{
    int i = 0;
    char *env_line = malloc(sizeof(char) * 255);

    for (i = 0; shell->tab[1][i] != '\0'; i++)
        env_line[i] = shell->tab[1][i];
    env_line[i] = '=';
    i++;
    if (shell->input_length > 2) {
        for (int j = 0; shell->tab[2][j] != '\n' && \
        shell->tab[2][j] != '\0'; i++, j++)
            env_line[i] = shell->tab[2][j];
    }
    env_line[i] = '\0';
    return (env_line);
}

void get_env_content(env_t *elem, char *line)
{
    int j = 0;
    int length = 0;

    for (length = 0; line[length] != '='; length++);
    elem->name = malloc(sizeof(char) * length + 2);
    elem->content = malloc(sizeof(char) * elem->size - length + 1);
    elem->name = my_strncpy(elem->name, line, length + 1);
    for (int i = length + 1; line[i] != '\0'; i++, j++) {
        elem->content[j] = line[i];
    }
    elem->content[j] = '\0';
}

void convert_env_in_tab(shell_t *shell)
{
    char **env;
    int i = 0;
    int size = 0;
    env_t *tmp;

    for (tmp = shell->list_env; tmp; tmp = tmp->next, size += 1);
    env = malloc(sizeof(char *) * size);
    for (tmp = shell->list_env; tmp; tmp = tmp->next, i += 1) {
        env[i] = malloc(sizeof(char) * tmp->size + 100);
        if (tmp->line == NULL)
            tmp = tmp->next;
        my_strcpy_tree(env[i], tmp->line);
    }
    env[i] = NULL;
    shell->env = env;
}
