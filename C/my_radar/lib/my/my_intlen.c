/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** my_intlen
*/

unsigned int my_intlen(int nb)
{
    unsigned int len = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        len++;
        nb /= 10;
    }
    return (len);
}
