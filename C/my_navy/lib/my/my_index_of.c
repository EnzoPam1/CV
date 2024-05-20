/*
** EPITECH PROJECT, 2023
** template
** File description:
** my_index_of
*/

#include "../../include/my.h"

int my_index_of(char const *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}
