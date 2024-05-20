/*
** EPITECH PROJECT, 2023
** my_put_unsigned_nbr
** File description:
** my_put_unsigned_nbr
*/

#include "../include/my.h"

int my_put_unsigned_nbr(unsigned int n)
{
    int count = 0;

    if (n >= 10) {
        count += my_put_unsigned_nbr(n / 10);
    }
    count += my_putchar(n % 10 + '0');
    return count;
}
