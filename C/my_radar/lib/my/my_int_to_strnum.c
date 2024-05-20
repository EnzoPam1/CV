/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** my_int_to_strnum
*/

#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "my.h"

static char *handle_special_cases(int nb)
{
    if (nb == INT_MIN)
        return my_strdup("-2147483648");
    if (nb == 0)
        return my_strdup("0");
    return NULL;
}

static char *convert_int_to_strnum(int nb, bool is_neg)
{
    char *strnum;
    unsigned int i = 0;
    unsigned int temp_nb;

    strnum = malloc(sizeof(char) * (my_intlen(nb) + 2));
    if (strnum == NULL) {
        return NULL;
    }
    temp_nb = is_neg ? -nb : nb;
    while (temp_nb != 0) {
        strnum[i] = nb % 10 + '0';
        i++;
        temp_nb /= 10;
    }
    if (is_neg) {
        strnum[i] = '-';
        i++;
    }
    strnum[i] = '\0';
    return my_revstr(strnum);
}

char *my_int_to_strnum(int nb)
{
    char *special_case_str;
    bool is_neg;
    char *result_str;

    special_case_str = handle_special_cases(nb);
    if (special_case_str != NULL) {
        return special_case_str;
    }
    is_neg = (nb < 0);
    result_str = convert_int_to_strnum(nb, is_neg);
    return result_str;
}
