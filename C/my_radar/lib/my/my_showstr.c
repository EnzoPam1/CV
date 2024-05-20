/*
** EPITECH PROJECT, 2023
** myshowstr
** File description:
** myshowstr day6
*/

#include "../../include/my.h"

int my_showstr(char const *str)
{
    if (str == 0) {
        return 0;
    }
    while (*str) {
        if (*str >= 32 && *str <= 126) {
            my_putchar(*str);
        } else {
            my_putchar('\\');
            my_putchar("0123456789abcdef"[(*str >> 4) & 0xF]);
            my_putchar("0123456789abcdef"[*str & 0xF]);
        }
        str++;
    }
    return 0;
}
