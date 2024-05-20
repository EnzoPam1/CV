/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-organized-enzo.pambout
** File description:
** my_strdup
*/

#include <stddef.h>
#include "../include/my.h"

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    char *dup = malloc(len + 1);

    if (dup == NULL) {
        return NULL;
    }
    my_strcpy(dup, src);
    return dup;
}
