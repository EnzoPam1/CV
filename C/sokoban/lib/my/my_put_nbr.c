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

    if (nb < 0) {
        write(1, "-", 1);
        return (1 + my_put_nbr(-nb));
    }
    if (nb >= 10)
        return (my_put_nbr(nb / 10) + my_put_nbr(nb % 10));
    c = nb + '0';
    write(1, &c, 1);
    return (1);
}
