/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include "../include/my.h"

int my_printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    for (; *format; format++) {
        if (*format == '%') {
            format++;
            count += handle_specifier(*format, &args);
        } else {
            my_putchar(*format);
            count++;
        }
    }
    va_end(args);
    return count;
}
