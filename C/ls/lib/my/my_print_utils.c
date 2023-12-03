/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** my_print_utils
*/

#include "../include/my.h"

void print_number_with_padding(int number, int field_width)
{
    int number_length = 0;
    int temp = number > 0 ? number : -number;

    do {
        number_length++;
        temp /= 10;
    } while (temp > 0);
    if (number < 0) {
        number_length++;
    }
    for (int i = 0; i < field_width - number_length; i++) {
        my_putchar(' ');
    }
    my_put_nbr(number);
}

void print_long_with_padding(long number, int field_width)
{
    int number_length = 0;
    long temp = number;

    if (number < 0) {
        number_length++;
        temp = -temp;
    }
    do {
        number_length++;
        temp /= 10;
    } while (temp > 0);
    for (int i = 0; i < field_width - number_length; i++) {
        my_putchar(' ');
    }
    my_put_long(number);
}
