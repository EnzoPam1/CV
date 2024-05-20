/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** my_puterr
*/

#include <unistd.h>

void my_puterr(char const *str)
{
    for (unsigned int i = 0; str[i]; i++)
        write(2, &(str[i]), 1);
}
