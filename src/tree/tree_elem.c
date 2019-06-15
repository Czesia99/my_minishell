/*
** EPITECH PROJECT, 2019
** Project main function
** File description:
** main
*/

#include "../../include/include.h"

elem_t *new_elem(char *cmd, char *separator)
{
    elem_t *new_elem = malloc(sizeof(elem_t));

    if (!new_elem) {
        perror("New elem malloc failed.\n");
        return (NULL);
    }
    new_elem->separator = NULL;
    new_elem->cmd = NULL;
    if (separator)
        new_elem->separator = my_strcpy_tree(new_elem->separator, separator);
    if (cmd)
        new_elem->cmd = my_strcpy_tree(new_elem->cmd, cmd);
    return (new_elem);
}

void free_elem(elem_t *elem)
{
    if (elem) {
        if (elem->cmd)
            free(elem->cmd);
        if (elem->separator)
            free(elem->separator);
        free(elem);
    }
}