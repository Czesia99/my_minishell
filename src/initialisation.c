/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** initialisation.c
*/

#include "include.h"

env_t *env_list_add(env_t *list, char *line)
{
    env_t *elem = malloc(sizeof(*elem));
    env_t *tmp;
    elem->size = my_strlen(line);
    elem->line = malloc(sizeof(char) * elem->size + 1);
    elem->next = NULL;

    if (elem->line == NULL) {
        perror("problem in allocated memory\n");
        exit (84);
    }
    elem->line = my_strcpy_tree(elem->line, line);
    get_env_content(elem, line);
    if (list == NULL)
        return (elem);
    for (tmp = list; tmp->next != NULL; tmp = tmp->next);
    tmp->next = elem;
    return (list);
}

env_t *env_list_init(char **env)
{
    env_t *list_env = malloc(sizeof(*list_env));
    list_env->line = NULL;
    list_env->name = NULL;
    list_env->content = NULL;
    list_env->size = 0;
    list_env->next = NULL;
    for (int i = 0; env[i] != NULL; i++)
        env_list_add(list_env, env[i]);
    return (list_env);
}

shell_t *get_shell_data(char *buff, char **env)
{
    int length = 0;
    shell_t *data = malloc(sizeof(*data));

    data->buff = NULL;
    data->env = env;
    data->tab = NULL;
    data->input_length = 0;
    data->list_env = env_list_init(env);
    data->tree = NULL;
    data->sep_tab = new_sep_tab();
    return (data);
}

void get_input(shell_t *data, char *buff)
{
    int length = 0;

    data->buff = buff;
    data->tab = my_str_to_word_array(buff, ' ');
    for (; data->tab[length] != NULL; length++);
    data->input_length = length;
}
