/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-sokoban-enzo.pambout
** File description:
** moves1
*/

#include "../include/sokoban.h"
#include "../include/my.h"

static void move_player_right(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y][position_x] =
        game_state_instance->initial_state[position_y][position_x];
    game_state_instance->position_x += 1;
    game_state_instance->game_map[position_y][position_x + 1] = 'P';
}

static void move_box_right(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y][position_x + 1] = 'X';
}

void go_right(struct game_state *game_state_instance)
{
    int position_y = game_state_instance->position_y;
    int position_x = game_state_instance->position_x;
    char next_cell = game_state_instance->game_map[position_y][position_x + 1];
    char next_next_cell = game_state_instance->game_map[position_y]
        [position_x + 2];

    if (next_cell == 'X' && (next_next_cell == ' ' || next_next_cell == 'O')) {
        move_player_right(game_state_instance, position_y, position_x);
        move_box_right(game_state_instance, position_y, position_x + 1);
    } else if (next_cell == ' ' || next_cell == 'O') {
        move_player_right(game_state_instance, position_y, position_x);
    }
}

static void move_player_left(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y][position_x] =
        game_state_instance->initial_state[position_y][position_x];
    game_state_instance->position_x -= 1;
    game_state_instance->game_map[position_y][position_x - 1] = 'P';
}

static void move_box_left(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y][position_x - 1] = 'X';
}

void go_left(struct game_state *game_state_instance)
{
    int position_y = game_state_instance->position_y;
    int position_x = game_state_instance->position_x;
    char next_cell = game_state_instance->game_map[position_y][position_x - 1];
    char next_next_cell = game_state_instance->game_map[position_y]
        [position_x - 2];

    if (next_cell == 'X' && (next_next_cell == ' ' || next_next_cell == 'O')) {
        move_player_left(game_state_instance, position_y, position_x);
        move_box_left(game_state_instance, position_y, position_x - 1);
    } else if (next_cell == ' ' || next_cell == 'O') {
        move_player_left(game_state_instance, position_y, position_x);
    }
}
