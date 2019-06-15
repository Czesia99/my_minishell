/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *inib(char *str)
{
    char *new_str = malloc(sizeof(char) * strlen(str) + 1);
    int j = 0;

    if (str[0] == '"') {
        for (int i = 1; str[i] != '"' && str[i]; i++) {
                if (str[i] == 92)
                    i++;
            new_str[j] = str[i];
            j++;
        }
    }
    else return (str);
    return (new_str);
}