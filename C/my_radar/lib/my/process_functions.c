/*
** EPITECH PROJECT, 2023
** process
** File description:
** process
*/

#include <stddef.h>
#include "../include/my.h"

int print_char_arg(va_list *args)
{
    return my_putchar(va_arg(*args, int));
}

int print_string_arg(va_list *args)
{
    return my_putstr(va_arg(*args, char *));
}

int print_int_arg(va_list *args)
{
    return my_put_nbr(va_arg(*args, int));
}

int print_octal_arg(va_list *args)
{
    unsigned int nbr = va_arg(*args, unsigned int);

    return my_putnbr_base(nbr, "01234567");
}

int print_unsigned_arg(va_list *args)
{
    unsigned int nbr = va_arg(*args, unsigned int);

    return my_putnbr_base(nbr, "0123456789");
}
