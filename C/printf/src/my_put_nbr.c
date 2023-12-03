/*
** EPITECH PROJECT, 2023
** Day03
** File description:
** Task07 | my_put_nbr.c
*/

#include <unistd.h>

int my_put_nbr(int nb)
{
    char c;
    int count = 0;

    if (nb < 0) {
        write(1, "-", 1);
        count = 1 + my_put_nbr(-nb);
    } else if (nb >= 10) {
        count = my_put_nbr(nb / 10) + my_put_nbr(nb % 10);
    } else {
        c = nb + '0';
        write(1, &c, 1);
        count = 1;
    }
    return count;
}
