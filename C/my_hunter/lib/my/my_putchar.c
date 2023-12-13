/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
