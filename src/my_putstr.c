/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/
#include <unistd.h>

void my_putchar(char);

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}