/*
** EPITECH PROJECT, 2023
** myisalpha
** File description:
** myisalpha
*/

int my_isalpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}
