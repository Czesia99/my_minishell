/*
** EPITECH PROJECT, 2019
** +
** File description:
** linked_list
*/

#include "include.h"

void print_linked(linked_t *list)
{
    linked_t *tmp = list;

    while (tmp) {
        my_putstr(tmp->str);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

linked_t *create_node(char *str)
{
    linked_t *node = NULL;

    node = malloc(sizeof(linked_t));
    node->str = my_strdup(str);
    node->next = NULL;

    return (node);
}

linked_t *create_list(char **tab)
{
    linked_t *current = create_node(tab[0]);
    linked_t *list = current;

    for (int i = 1; tab[i]; i++) {
        current->next = create_node(tab[i]);
        current = current->next;
    }
    return (list);
}

linked_t *find_node(linked_t *list, char *cmp, int i)
{
    linked_t *new = list;

    while (new->next) {
        if (my_strncmp(cmp, new->str, i) == 0) return (new);
        new = new->next;
    }
    return (new);
}
