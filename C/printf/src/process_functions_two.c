/*
** EPITECH PROJECT, 2023
** process
** File description:
** process
*/

#include <stddef.h>
#include "../include/my.h"

int print_hex_lowercase_arg(va_list *args)
{
    unsigned int nbr = va_arg(*args, unsigned int);

    return my_putnbr_base(nbr, "0123456789abcdef");
}

int print_hex_uppercase_arg(va_list *args)
{
    unsigned int nbr = va_arg(*args, unsigned int);

    return my_putnbr_base(nbr, "0123456789ABCDEF");
}

int print_pointer_arg(va_list *args)
{
    unsigned long int addr = va_arg(*args, unsigned long int);

    my_putstr("0x");
    return my_putnbr_base_ulong(addr, "0123456789abcdef");
}

int print_percent_sign(va_list *args)
{
    (void)args;
    return my_putchar('%');
}

int print_binary_arg(va_list *args)
{
    unsigned int nbr = va_arg(*args, unsigned int);

    return my_putnbr_base(nbr, "01");
}
