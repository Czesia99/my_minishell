/*
** EPITECH PROJECT, 2019
** Project main function
** File description:
** main
*/

#include "../../include/include.h"

char *my_strcpy_tree(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL)
        dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    else if (src == NULL)
        return (dest);
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
