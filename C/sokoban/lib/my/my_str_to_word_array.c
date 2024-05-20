/*
** EPITECH PROJECT, 2023
** template
** File description:
** my_str_to_word_array_core
*/

#include <stdlib.h>
#include <ctype.h>
#include "../../include/my.h"

static int my_delim(char s, char *lim)
{
    int i = 0;

    while (lim[i]) {
        if (s == lim[i])
            return (-1);
        i++;
    }
    return (0);
}

static int while_delim(char const *str, int i, char *lim)
{
    if (my_delim(str[i], lim) == -1) {
        while (my_delim(str[i], lim) == -1)
            i++;
        i -= 1;
    }
    return (i);
}

int count_word(char const *str, char *lim)
{
    int i = 0;
    int res = 1;

    while (str[i]) {
        i = while_delim(str, i, lim);
        res += 1;
        i++;
    }
    return (res);
}

int word_size(char *str, int i, char *lim)
{
    int len = 0;

    while (my_delim(str[i], lim) == 0 && str[i]) {
        len++;
        i++;
    }
    return (len);
}

int skip_delimiters(char *str, int i, char *lim)
{
    while (my_delim(str[i], lim) == -1 && str[i]) {
        i++;
    }
    return i;
}

void copy_word_to_tab(word_processing_t *wp, char *lim)
{
    int x = 0;

    wp->tab[*(wp->y)] = malloc(sizeof(char) * (word_size(wp->str, *(wp->i),
        lim) + 1));
    while (my_delim(wp->str[*(wp->i)], lim) == 0 && wp->str[*(wp->i)]) {
        wp->tab[*(wp->y)][x] = wp->str[*(wp->i)];
        x++;
        (*(wp->i))++;
    }
    wp->tab[*(wp->y)][x] = '\0';
    (*(wp->y))++;
}

char **my_str_to_word_array(char *str, char *lim)
{
    int nb_word = count_word(str, lim) + 2;
    int i = 0;
    int y = 0;
    char **tab = malloc(sizeof(char *) * (nb_word + 1));
    word_processing_t wp = {tab, str, &i, &y};

    while (str[i]) {
        i = skip_delimiters(str, i, lim);
        copy_word_to_tab(&wp, lim);
        i = skip_delimiters(str, i, lim);
    }
    tab[y] = NULL;
    return tab;
}
