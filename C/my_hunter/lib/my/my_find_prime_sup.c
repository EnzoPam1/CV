/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** task07
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    while (1) {
        if (my_is_prime(nb)) {
            return nb;
        }
        nb++;
    }
}
