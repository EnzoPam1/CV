/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** task05
*/

int my_compute_square_root(int nb)
{
    int sqrt_result = 0;

    if (nb < 0) {
        return 0;
    }
    while (sqrt_result * sqrt_result <= nb) {
        if (sqrt_result * sqrt_result == nb) {
            return sqrt_result;
        }
        sqrt_result++;
    }
    return 0;
}
