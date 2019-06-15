/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include "include.h"

char *last_space(char *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (str[i] == ' ' && str[i+1] == '\0') {
            str[i] = '\0';
        }
    }
    return (str);
}

char *clear_tab(char *str)
{
    int i = 0;

    for (;str[i];i++)  {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return (str);
}

char *clear_str(char *str)
{
    int len = my_strlen(str);
    char *new_str = NULL;
    int j = 0;

    new_str = malloc(sizeof(char) * len + 1);
    new_str = clear_tab(str);
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' && str[i + 1] == ' ') {
            new_str[j] = str[i];
            j++;
            new_str[j] = ' ';
            j++;
        }
        else if (str[i] != ' ' && str[i] != '\t') {
            new_str[j] = str[i];
            j++;
        }
    new_str[j++] = '\0';
    new_str = last_space(new_str);
    return (new_str);
}