/*
** EPITECH PROJECT, 2023
** template
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <string.h>
#include "../../include/my.h"

static int add_word_from_substr(t_word_params *params, int end)
{
    char *word = duplicate_word(params->str, params->start, end);

    if (word == NULL) {
        return 0;
    }
    params->words[params->index] = word;
    (params->index)++;
    return 1;
}

static void process_char(char current_char, int i, t_word_params *params)
{
    if (!is_word_char(current_char) && params->start != -1) {
        if (!add_word_from_substr(params, i)) {
            params->words[params->index] = NULL;
        }
        params->start = -1;
    } else if (is_word_char(current_char) && params->start == -1) {
        params->start = i;
    }
}

int fill_words_array(char **words, const char *str)
{
    t_word_params params = {words, str, -1, 0};

    for (int i = 0; str[i]; i++) {
        process_char(str[i], i, &params);
    }
    if (params.start != -1) {
        if (!add_word_from_substr(&params, strlen(str))) {
            return 0;
        }
    }
    words[params.index] = NULL;
    return 1;
}
