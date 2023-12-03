/*
** EPITECH PROJECT, 2023
** Day07
** File description:
** task02
*/

char *my_strcat(char *dest, char const *src)
{
    char *p = dest;

    while (*p != '\0') {
        p++;
    }
    while (*src != '\0') {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return dest;
}
