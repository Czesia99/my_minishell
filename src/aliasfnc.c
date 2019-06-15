/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include "include.h"

char **malloctab1(char **tab)
{
    tab = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++)
        tab[i] = malloc(sizeof(char) * 100);

    return (tab);
}

int parsing_equal(char *buff)
{
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '=')
            return (0);
    }
    return (1);
}

siple_t stock_alias(char *buff, char **tabalias, siple_t s)
{
    char **tab = 0;

    if (parsing_equal(buff) == 0)
        tab = my_str_to_word_array(buff+6, '=');
    else return (s);
    for (int j = 0; j < s.i; j++) {
        if (my_strcmp_equal(tabalias[j], tab[0]) == 0) {
            tabalias[j] = my_strdup(tab[0]);
            tabalias[j] = my_strcat(tabalias[j], tab[1], 1, '=');
            return (s);
        }
    }
    tabalias[s.i] = my_strdup(tab[0]);
    tabalias[s.i] = my_strcat(tabalias[s.i], tab[1], 1, '=');
    s.i++;
    return (s);
}

void printalias(char **taballias, siple_t s)
{
    for (int i = 0; i < s.i; i++) {
        printf("%s\n", taballias[i]);
    }
}

char *parsetab(char **tab, siple_t s)
{
    for (int i = 0; i < s.i; i++) {
        if (my_strcmp_equal(tab[i], s.buff) == 0) {
            s.buff = my_strdup_equal(tab[i]);
            return (s.buff);
        }
    }
    return (s.buff);
}