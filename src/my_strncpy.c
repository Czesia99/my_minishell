/*
** EPITECH PROJECT, 2018
** my_strncpy.c
** File description:
** my_strncpy
*/

#include "include.h"

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}