/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** gnl.c
*/

#include "my_navy.h"

int perform_check(char *str)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == '\n') {
            return 84;
        }
        i++;
    }
    return 0;
}

char *concatenate_strings(char *result, char *buffer, int size)
{
    int i = 0;
    int count = 0;
    char *ret;

    for (i = 0; result[i]; i++);
    ret = malloc(sizeof(char) * (i + size + 1));
    if (!ret) {
        return NULL;
    }
    for (i = 0; result[i]; i++) {
        ret[i] = result[i];
    }
    for (count = 0; size != 0 && count < size; count++) {
        ret[i + count] = buffer[count];
    }
    ret[i + size] = '\0';
    return ret;
}

char *extract_remaining_string(char *str)
{
    int i = 0;
    char *res = NULL;
    int j = 0;

    while (str[i] && str[i] != '\n') {
        i++;
    }
    if (str[i] == '\n')
        i++;
    for (j = 0; str[j]; j++);
    res = malloc(sizeof(char) * ((j - i) + 1));
    if (res == NULL) {
        return NULL;
    }
    for (j = 0; str[i]; j++) {
        res[j] = str[i];
        i++;
    }
    res[j] = '\0';
    return res;
}

static char *prepare_result(char **temp)
{
    char *result;

    if (my_strlen(*temp) != 0) {
        result = concatenate_strings(*temp, NULL, 0);
    } else {
        result = "\0";
    }
    return result;
}

static int handle_read(int fd, char **result, char *buffer)
{
    int size = 1;

    while (size != 0) {
        size = read(fd, buffer, READ_SIZE);
        if (size <= 0) {
            break;
        }
        *result = concatenate_strings(*result, buffer, size);
        if (perform_check(*result) == 84) {
            break;
        }
    }
    return size;
}

char *finalize_result(char *result, char **temp, int size)
{
    if (result == NULL) {
        return NULL;
    }
    *temp = extract_remaining_string(result);
    if (*temp == NULL || size == -1) {
        return NULL;
    }
    if (size == 0 && my_strlen(result) == 0) {
        return NULL;
    }
    for (int j = 0; result[j]; j++) {
        if (result[j] == '\n') {
            result[j] = '\0';
        }
    }
    return result;
}

char *read_next_line(int fd)
{
    static char buffer[READ_SIZE] = {0};
    static char *temp = "\0";
    char *result;
    int size;

    if (READ_SIZE <= 0 || fd == -1) {
        return NULL;
    }
    result = prepare_result(&temp);
    size = handle_read(fd, &result, buffer);
    return finalize_result(result, &temp, size);
}
