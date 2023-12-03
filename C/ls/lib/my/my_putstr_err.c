/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** my_putstr_err
*/

#include <unistd.h>
#include "../../include/my.h"

void my_putstr_err(const char *str)
{
    while (*str) {
        write(2, str, 1);
        str++;
    }
}
