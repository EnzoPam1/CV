/*
** EPITECH PROJECT, 2023
** revstr
** File description:
** revstr day6
*/

#include <unistd.h>

char *my_revstr(char *str)
{
    int left;
    int right;
    char temp;

    if (!str)
        return (NULL);
    for (right = 0; str[right] != '\0'; right++);
    right--;
    left = 0;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    return (str);
}
