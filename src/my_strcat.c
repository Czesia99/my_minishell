/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include <stdlib.h>
#include <stdio.h>

static int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_strcat(char *str, char *c, int slash, char ch)
{
    int len = my_strlen(str);
    int len2 = my_strlen(c);
    char *new_str = malloc(sizeof(char) * (len + len2 + slash + 1));
    int i = 0;
    int j = 0;

    for (; str[i]; i++)
        new_str[i] = str[i];
    if (ch != 'a')
        new_str[i] = ch;
    i++;
    while (c[j]) {
        new_str[i] = c[j];
        j++;
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

char *my_strcat1(char *str, char *c)
{
    int len = my_strlen(str) + my_strlen(c) + 2;
    char *new_str = malloc(sizeof(char) * len);
    int i = 0;
    int j = 0;
    for (int w = 0; w < len; w++) new_str[w] = '\0';
    for (; str[i]; i++) new_str[i] = str[i];
    while (c[j]) {
        new_str[i] = c[j];
        j++;
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
