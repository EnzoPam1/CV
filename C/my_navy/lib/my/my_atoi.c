/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-organized-enzo.pambout
** File description:
** my_atoi
*/

#include <limits.h>

int my_atoi(const char *str)
{
    int result = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
        || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0'
            > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}
