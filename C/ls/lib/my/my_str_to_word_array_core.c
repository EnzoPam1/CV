/*
** EPITECH PROJECT, 2023
** template
** File description:
** my_str_to_word_array_core
*/

#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include "../../include/my.h"

int is_word_char(char c)
{
    return isalnum((unsigned char)c);
}

static int count_words(char const *str)
{
    int count = 0;
    int in_word = 0;
    char current_char = *str;

    while (current_char != '\0') {
        if (is_word_char(current_char)) {
            count += in_word == 0;
            in_word = 1;
        } else {
            in_word = 0;
        }
        str++;
        current_char = *str;
    }
    return count;
}

char **my_str_to_word_array(char const *str)
{
    int word_count = count_words(str);
    char **words = malloc((word_count + 1) * sizeof(char *));

    if (str == NULL) {
        return NULL;
    }
    if (words == NULL) {
        return NULL;
    }
    if (!fill_words_array(words, str)) {
        free(words);
        return NULL;
    }
    return words;
}
