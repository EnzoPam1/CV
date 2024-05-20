/*
** EPITECH PROJECT, 2023
** Day03
** File description:
** Task04 | my_isneg.c
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return 0;
}
