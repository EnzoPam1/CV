/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** my_str_utils
*/

#include "../include/my.h"

char *my_strcat_with_slash(char *dest, const char *src1, const char *src2)
{
    char *p = dest;

    while (*src1 != '\0') {
        *p++ = *src1++;
    }
    *p++ = '/';
    while (*src2 != '\0') {
        *p++ = *src2++;
    }
    *p = '\0';
    return dest;
}
