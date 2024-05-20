/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-sokoban-enzo.pambout
** File description:
** starting
*/

#include "../include/sokoban.h"
#include "../include/my.h"

void displaycurse(struct game_state *game_state_instance)
{
    int position_y = 0;

    while (game_state_instance->game_map[position_y] != NULL) {
        mvprintw(position_y, 0, "%s", game_state_instance->game_map
            [position_y]);
        position_y++;
    }
}

void start_sokoban(struct game_state *game_state_instance)
{
    int input = 0;

    displaycurse(game_state_instance);
    initscr();
    noecho();
    curs_set(0);
    while (check_win(game_state_instance) != 0) {
        input = getch();
        moves(game_state_instance, input);
        displaycurse(game_state_instance);
        refresh();
        if (check_loose(game_state_instance->game_map) == 0 &&
            check_win(game_state_instance) != 0) {
            endwin();
            exit(1);
        }
    }
    endwin();
    exit(0);
}

void change_carac(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    if (game_state_instance->initial_state[position_y][position_x] == 'X' ||
        game_state_instance->initial_state[position_y][position_x] == 'P') {
        game_state_instance->initial_state[position_y][position_x] = ' ';
    }
}

void changes(struct game_state *game_state_instance)
{
    int position_y = 0;
    int position_x = 0;

    while (game_state_instance->initial_state[position_y] != NULL) {
        position_x = 0;
        while (game_state_instance->initial_state[position_y][position_x]) {
            change_carac(game_state_instance, position_y, position_x);
            position_x++;
        }
        position_y++;
    }
}

static int scan_row_for_player(struct game_state *game_state_instance,
    int position_y)
{
    for (int position_x = 0; game_state_instance->game_map[position_y]
        [position_x]; position_x++) {
        if (game_state_instance->game_map[position_y][position_x] == 'P') {
            game_state_instance->position_y = position_y;
            game_state_instance->position_x = position_x;
            return 1;
        }
    }
    return 0;
}

static void find_player_position(struct game_state *game_state_instance)
{
    for (int position_y = 0; game_state_instance->game_map[position_y]
        != NULL; position_y++) {
        if (scan_row_for_player(game_state_instance, position_y)) {
            return;
        }
    }
    exit(84);
}

void fill_struct(struct game_state *game_state_instance)
{
    game_state_instance->position_y = 0;
    game_state_instance->position_x = 0;
    game_state_instance->initial_state =
        my_str_to_word_array(game_state_instance->data_buffer, "\n");
    game_state_instance->game_map =
        my_str_to_word_array(game_state_instance->data_buffer, "\n");
    find_player_position(game_state_instance);
    game_state_instance->saveposition_y = game_state_instance->position_y;
    game_state_instance->saveposition_x = game_state_instance->position_x;
    changes(game_state_instance);
}
