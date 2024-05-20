/*
** EPITECH PROJECT, 2023
** handlers
** File description:
** handlers
*/

#include <stddef.h>
#include "../include/my.h"

specifiers_t *get_specifiers(void)
{
    static specifiers_t specifiers[] = {
        {'c', print_char_arg},
        {'s', print_string_arg},
        {'d', print_int_arg},
        {'i', print_int_arg},
        {'o', print_octal_arg},
        {'u', print_unsigned_arg},
        {'x', print_hex_lowercase_arg},
        {'X', print_hex_uppercase_arg},
        {'p', print_pointer_arg},
        {'%', print_percent_sign},
        {'b', print_binary_arg},
        {0, NULL}
    };

    return specifiers;
}

int handle_specifier(char specifier, va_list *args)
{
    int i = 0;
    specifiers_t *specifiers = get_specifiers();

    while (specifiers[i].specifier != 0) {
        if (specifier == specifiers[i].specifier) {
            return specifiers[i].func(args);
        }
        i++;
    }
    return 0;
}
