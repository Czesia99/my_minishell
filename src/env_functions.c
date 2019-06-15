/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** env
*/

#include "include.h"

void do_exit(shell_t *data, linked_t *list)
{
    (void)data;
    (void)list;
    exit(0);
    return;
}

void do_env(shell_t *shell, linked_t *list)
{
    (void)list;
    for (int i = 0; shell->env[i] != NULL; i++)
        printf("%s\n", shell->env[i]);
    return;
}

void setenv_existing_line(env_t *tmp, char *line)
{
    free(tmp->line);
    tmp->line = malloc(sizeof(char) * my_strlen(line) + 10);
    my_strcpy_tree(tmp->line, line);
}

void do_setenv(shell_t *shell, linked_t *list)
{
    (void)list;
    env_t *tmp = shell->list_env;
    char *line = NULL;

    if (check_env_args(shell) > 0)
        return;
    line = create_env_line(shell);
    for (; tmp; tmp = tmp->next) {
        if (tmp->name == NULL)
            tmp = tmp->next;
        if (my_strncmp(tmp->name, shell->tab[1], my_strlen(tmp->name) - 1) \
        == 0) {
            setenv_existing_line(tmp, line);
            convert_env_in_tab(shell);
            return;
        }
    }
    env_list_add(shell->list_env, create_env_line(shell));
    convert_env_in_tab(shell);
    return;
}

void do_unsetenv(shell_t *shell, linked_t *list)
{
    (void)list;
    env_t *tmp;
    env_t *prev;

    for (int i = 1; shell->tab[i] != NULL; i++) {
        tmp = shell->list_env;
        prev = tmp;
        for (; tmp; tmp = tmp->next) {
            if (tmp->name == NULL)
                tmp = tmp->next;
            if (my_strncmp(tmp->name, shell->tab[i], \
            my_strlen(tmp->name) - 1) == 0) {
                prev->next = tmp->next;
                free(tmp);
            }
            prev = tmp;
        }
    }
    convert_env_in_tab(shell);
    return;
}