/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** my_strlen
*/

#include "include.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}