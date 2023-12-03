/*
** EPITECH PROJECT, 2023
** Day06
** File description:
** putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
