/*
** EPITECH PROJECT, 2019
** ..
** File description:
** ..
*/

#include <unistd.h>

void my_putchar(char);

void my_put_nbr(int nb)
{
    int k = 0;
    if (nb > 10) {
        my_put_nbr(nb/10);
    }
        k = nb % 10;
        my_putchar( k + 48);
}
