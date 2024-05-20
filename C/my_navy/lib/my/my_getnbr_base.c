/*
** EPITECH PROJECT, 2023
** template
** File description:
** my_getnbr_base
*/

#include "../../include/my.h"

static int is_valid(char c, char const *base)
{
    int i = 0;

    while (base[i] != '\0') {
        if (c == base[i])
            return (1);
        i++;
    }
    return (0);
}

static int find_minus(char const *str, int *index)
{
    int minus_count = 0;
    int i = *index;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            minus_count++;
        i++;
    }
    *index = i;
    return (minus_count % 2 == 1 ? -1 : 1);
}

int my_getnbr_base(char const *str, char const *base)
{
    int result = 0;
    int base_length = my_strlen(base);
    int i = 0;
    int is_positive = 1;

    if (base_length < 2)
        return (0);
    is_positive = find_minus(str, &i);
    while (str[i] != '\0' && is_valid(str[i], base)) {
        result = result * base_length + my_index_of(base, str[i]);
        i++;
    }
    return (result * is_positive);
}
