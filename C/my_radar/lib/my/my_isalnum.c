/*
** EPITECH PROJECT, 2023
** myisalnum
** File description:
** myisalnum
*/

int my_isalnum(int c)
{
    if ((c >= '0' && c <= '9') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
}
