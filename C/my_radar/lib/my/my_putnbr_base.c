/*
** EPITECH PROJECT, 2023
** putnbrbase
** File description:
** putnbrbase day6
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putnbr_base(unsigned int nbr, char const *base)
{
    int base_length = my_strlen(base);
    int count = 0;

    if (base_length < 2)
        return (0);
    if (nbr >= (unsigned int)base_length) {
        count += my_putnbr_base(nbr / base_length, base);
    }
    my_putchar(base[nbr % base_length]);
    count++;
    return count;
}
