/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** my_put_long
*/

#include "../include/my.h"

void my_put_long(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_long(nb / 10);
        my_put_long(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}
