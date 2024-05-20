/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-organized-enzo.pambout
** File description:
** my_strtok
*/

#include <stddef.h>
#include "../include/my.h"

static int is_delimiter(char character, const char *delim)
{
    for (const char *d = delim; *d != '\0'; d++) {
        if (character == *d) {
            return 1;
        }
    }
    return 0;
}

static char *skip_delimiters(char *str, const char *delim)
{
    while (*str && is_delimiter(*str, delim)) {
        str++;
    }
    return str;
}

static char *find_delimiter(char *str, const char *delim)
{
    while (*str && !is_delimiter(*str, delim)) {
        str++;
    }
    return str;
}

char *my_strtok(char *str, const char *delim)
{
    static char *next_token = NULL;
    char *token_start;

    if (str != NULL) {
        next_token = str;
    }
    if (next_token == NULL || *next_token == '\0') {
        return NULL;
    }
    next_token = skip_delimiters(next_token, delim);
    token_start = next_token;
    next_token = find_delimiter(next_token, delim);
    if (*next_token) {
        *next_token = '\0';
        next_token++;
    } else {
        next_token = NULL;
    }
    return token_start;
}
