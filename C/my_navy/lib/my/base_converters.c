/*
** EPITECH PROJECT, 2023
** base_converters
** File description:
** base_converters
*/

#include "../include/my.h"

unsigned int my_putnbr_base_ulong(unsigned long int nbr, char *base)
{
    unsigned long int base_len = my_strlen(base);
    unsigned int size = 0;

    if (nbr >= base_len) {
        size += my_putnbr_base_ulong(nbr / base_len, base);
        size += my_putnbr_base_ulong(nbr % base_len, base);
    } else {
        size += my_putchar(base[nbr]);
    }
    return size;
}
