/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0) {
        return 0;
    } else if (p == 0) {
        return 1;
    } else {
        return nb * my_compute_power_rec(nb, p - 1);
    }
    return result;
}
