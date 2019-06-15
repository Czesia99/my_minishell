/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_getline
*/

#include "include.h"

char *my_getline(void)
{
    size_t size = 0;
    char *buff = NULL;
    int ret;

    ret = getline(&buff, &size, stdin);
    if (ret == -1) return (NULL);
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '\n') {
            buff[i] = '\0';
            return (buff);
        }
    }
    return (buff);
}