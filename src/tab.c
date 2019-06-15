/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** tab
*/

#include "include.h"

char **copy_tab(char **envp)
{
    char **tab = NULL;
    int len = 0;
    int len2 = 0;
    int i = 0;
    int j = 0;

    for (int a = 0; envp[a]; a++, len++);
    tab = malloc(sizeof(char *) * (len + 1));
    for (; envp[i]; i++) {
        len2 = my_strlen(envp[i]);
        tab[i] = malloc(sizeof(char) * (len2 + 1));
        len2 = 0;
        for (j = 0; envp[i][j]; j++)
            tab[i][j] = envp[i][j];
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}

char **list_to_tab(linked_t *list)
{
    char **tab = NULL;
    int len = 0;
    int len2 = 0;
    linked_t *tmp = list;
    int j = 0;
    int i = 0;

    for (int a = 0; tmp->next; a++, len++)
        tmp = tmp->next;
    tab = malloc(sizeof(char *) * (len + 1));
    tmp = list;
    for (; tmp->next; i++) {
        len2 = my_strlen(tmp->str);
        tab[i] = malloc(sizeof(char) * (len2 + 1));
        len2 = 0;
        for (j = 0; tmp->str[j]; j++)
            tab[i][j] = tmp->str[j];
        tab[i][j] = '\0';
        tmp = tmp->next;
    }
    tab[i] = NULL;
    return (tab);
}