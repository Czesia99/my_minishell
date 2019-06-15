/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 1));
    int i = 0;

    for (; str[i]; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}

char *my_strdup_equal(char const *str)
{
    int len = my_strlen(str);
    char *new_str = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    for (; str[i] != '='; i++);
    i++;
    for (; str[i]; i++, j++)
        new_str[j] = str[i];
    new_str[j] = '\0';
    return (new_str);
}
