/*
** EPITECH PROJECT, 2023
** strstr
** File description:
** strstr day6
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    char *begin;
    char const *pattern;

    if (!*to_find)
        return (str);
    while (*str){
        begin = str;
        pattern = to_find;
        while (*str && *pattern && *str == *pattern){
            str++;
            pattern++;
        }
        if (!*pattern)
            return (begin);
        str = begin + 1;
    }
    return (NULL);
}
