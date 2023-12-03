/*
** EPITECH PROJECT, 2023
** Day04
** File description:
** Task03 | my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
