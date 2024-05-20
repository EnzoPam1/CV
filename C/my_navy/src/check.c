/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** check_my_file.c
*/

#include "my_navy.h"

int validate_player_file(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] >= '1' && str[i] <= '8') || str[i] == '\n'
        || (str[i] >= 'A' && str[i] <= 'H') || str[i] == ':')
            i++;
        else
            return (84);
    }
    return (0);
}

static int check_char(char expected, char actual)
{
    return expected != actual;
}

int validate_ship_sizes(char *str)
{
    int error = 0;
    char nb = '2';

    for (int i = 0; i < 25; i += 8) {
        error += check_char(nb, str[i]);
        nb++;
    }
    return error;
}

int validate_colons_and_newlines(char *str)
{
    int error = 0;

    for (int i = 1; i < 26; i += 8) {
        error += check_char(':', str[i]);
    }
    for (int i = 4; i < 29; i += 8) {
        error += check_char(':', str[i]);
    }
    for (int i = 7; i < 26; i += 8) {
        error += check_char('\n', str[i]);
    }
    return error;
}

int validate_positions(char *str)
{
    int error = 0;

    for (int i = 2; i < 27; i += 8) {
        if (str[i] < 'A' || str[i] > 'H') {
            error++;
        }
    }
    for (int i = 3; i < 28; i += 8) {
        if (str[i] < '1' || str[i] > '8') {
            error++;
        }
    }
    for (int i = 6; i < 31; i += 8) {
        if (str[i] < '1' || str[i] > '8') {
            error++;
        }
    }
    return error;
}

int validate_game_map(char *str)
{
    int error = 0;

    error += validate_ship_sizes(str);
    error += validate_colons_and_newlines(str);
    error += validate_positions(str);
    return error;
}
