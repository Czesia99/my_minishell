/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** what_to_do
*/

#include "include.h"

static builtin_t builtin_tab[] = {
    {"cd", &do_cd},
    {"env", &do_env},
    {"exit", &do_exit},
    {"setenv", &do_setenv},
    {"unsetenv", &do_unsetenv}
};

int check_builtins(shell_t *data, linked_t *list)
{
    int nop = 0;
    int ncmp_tab[] = {2, 3, 4, 6, 8};
    
    for (int i = 0; i < 5; i++) {
        if (my_strncmp(data->tab[0], builtin_tab[i].cmd, ncmp_tab[i]) == 0)
            builtin_tab[i].function(data, list);
        else
            nop += 1;
    }
    if (nop == 5)
        return (10);
}