/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** my_strtol
*/

#include <stdbool.h>
#include <stdio.h>

int my_strtol(char *str, char **endptr)
{
    unsigned int i = 0;
    int nb = 0;
    bool is_neg = false;

    if (str[0] == '-' && str[1]) {
        i++;
        is_neg = true;
    }
    while (str[i] == ' ')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        nb = (nb * 10) + str[i] - '0';
        i++;
    }
    (*endptr) = (*endptr + i);
    return ((is_neg) ? -nb : nb);
}
