/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include "include.h"

siple_t alias(siple_t s, char **tabalias)
{
    char **tab = 0;

    tab = my_str_to_word_array(s.buff, ' ');
    if (my_strcmp(tab[0], "alias") == 0) {
        if (my_strlen(s.buff) == 5)
            printalias(tabalias, s);
        else {
            s = stock_alias(s.buff, tabalias, s);
        }
        s.a = 11;
    }
    else
        s.buff = parsetab(tabalias, s);
    return (s);
}