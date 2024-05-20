/*
** EPITECH PROJECT, 2023
** DAy07
** File description:
** task03
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    char *p = dest;

    while (*p != '\0') {
        p++;
    }
    while (*src != '\0' && nb > 0) {
        *p = *src;
        p++;
        src++;
        nb--;
    }
    *p = '\0';
    return dest;
}
