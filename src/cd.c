/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include "include.h"

char *change_old(linked_t **node)
{
    int i = 0;
    char *new_str;

    new_str = malloc(sizeof(char) * my_strlen((*node)->str) - i);
    for (; (*node)->str[i + 3]; i++) {
        new_str[i] = (*node)->str[i + 3];
    }
    new_str[i] = '\0';
    return (new_str);
}

int update_pwd(linked_t **node, char *dir, char c)
{
    (*node)->str = my_strcat((*node)->str, dir, 1, c);
    return (0);
}

int update_oldpwd(linked_t **node, linked_t **node2)
{
    char *str;
    char str1[] = "OLDPWD";

    (*node2)->str = change_old(node);
    str = malloc(sizeof(char) * my_strlen((*node)->str) * 1000);
    str = my_strdup(str1);
    str = my_strcat1(str, (*node)->str+3);
    (*node)->str = my_strdup(str);
    return (0);
}

linked_t *call(char **av, char **envp, char *buff, char *cmp)
{
    char **tab = my_str_to_word_array(buff, ' ');
    char **env = copy_tab(envp);
    linked_t *link = create_list(env);
    linked_t *node_founded = find_node(link, cmp, 3);
    linked_t *node_fold = find_node(link, "OLDPWD", 6);

    (void) av;
    update_pwd(&node_founded, tab[1], '/');
    update_oldpwd(&node_founded, &node_fold);
    return (link);
}

void do_cd(shell_t *data, linked_t *list)
{
    list = call(data->tab, data->env, data->buff, "PWD");
    if (data->tab[1] == NULL)
        return;
    chdir(data->tab[1]);
    return;
}
