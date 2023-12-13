/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int result;

    if (p < 0){
        result = 0;
    } else {
        result = 1;
        for (int i = 0; i < p; i++) {
            result *= nb;
        }
    }
    return result;
}
