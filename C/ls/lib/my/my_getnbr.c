/*
** EPITECH PROJECT, 2023
** Day04
** File description:
** my_getnbr.c
*/

#include "../../include/my.h"

static int check_sign_and_skip_zeros(const char **str)
{
    int is_positive = 1;

    while (**str == '-' || **str == '+') {
        if (**str == '-') {
            is_positive = -is_positive;
        }
        (*str)++;
    }
    while (**str == '0')
        (*str)++;
    return is_positive;
}

static int convert_str_to_int(const char *str, int is_positive)
{
    int result = 0;

    while (*str >= '0' && *str <= '9') {
        if (result > (2147483647 - (*str - '0')) / 10)
            return 0;
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * is_positive;
}

int my_getnbr(char const *str)
{
    int is_positive = check_sign_and_skip_zeros(&str);

    return convert_str_to_int(str, is_positive);
}
