/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** task06
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
