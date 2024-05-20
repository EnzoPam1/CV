/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** display.c
*/

#include "my_navy.h"

void display_help_message(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player. "
    "pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing the "
    "positions of the ships.\n");
}

void display_game_map(char **map)
{
    int i = 0;
    int j;
    int x = 0;

    my_printf(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
    for (i = 0; i < 8; i++) {
        j = 0;
        my_printf("%d|", i + 1);
        while (j < 8) {
            my_printf("%c ", map[x][j]);
            j++;
        }
        x++;
        my_putchar('\n');
    }
}

static int count_ship(char map_char, int *count)
{
    if (map_char == '2' || map_char == '3' || map_char == '4' ||
        map_char == '5') {
        (*count)++;
    }
    return 0;
}

int check_for_collisions(char **map)
{
    int y = 0;
    int x;
    int count = 0;

    while (map[y] != NULL) {
        for (x = 0; map[y][x] != '\0'; x++) {
            count_ship(map[y][x], &count);
        }
        y++;
    }
    if (count != 14) {
        my_putstr("Collision between boats\n");
        return (84);
    }
    return (0);
}

void display_full_game_status(game_status_t *status)
{
    my_printf("my positions:\n");
    display_game_map(status->player_map);
    my_printf("\nenemy's positions:\n");
    display_game_map(status->opponent_map);
}

int check_win_condition(char **map)
{
    int nb = 0;
    int y = 0;
    int x = 0;

    while (map[y]) {
        x = 0;
        while (map[y][x]) {
            nb += (map[y][x] == 'x' ? 1 : 0);
            x++;
        }
        y++;
    }
    return (nb);
}
