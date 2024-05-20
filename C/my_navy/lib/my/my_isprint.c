/*
** EPITECH PROJECT, 2023
** myisprint
** File description:
** myisprint
*/

int my_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return 1;
    return 0;
}
