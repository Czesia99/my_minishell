/*
** EPITECH PROJECT, 2019
** Project main function
** File description:
** main
*/

#include "../../include/include.h"

sep_tab_t *new_sep_tab(void)
{
    sep_tab_t *new_tab = malloc(sizeof(sep_tab_t) * TOTAL_SEP);

    for (int i = 0; i < TOTAL_SEP; i += 1)
        new_tab[i].sep = NULL;
    new_tab[0].sep = my_strcpy_tree(NULL, ";");
    new_tab[0].sep_value = semi_colon;
    new_tab[1].sep = my_strcpy_tree(NULL, "dleft");
    new_tab[1].sep_value = dble_l_chevron;
    new_tab[2].sep = my_strcpy_tree(NULL, "&&");
    new_tab[2].sep_value = dble_and;
    new_tab[3].sep_value = dble_pipe;
    new_tab[4].sep_value = dble_r_chevron;
    new_tab[5].sep = my_strcpy_tree(NULL, "<");
    new_tab[5].sep_value = l_chevron;
    new_tab[6].sep = my_strcpy_tree(NULL, ">");
    new_tab[6].sep_value = r_chevron;
    new_tab[7].sep = my_strcpy_tree(NULL, "|");
    new_tab[7].sep_value = piipe;
    return (new_tab);
}