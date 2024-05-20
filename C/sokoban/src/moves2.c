/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-sokoban-enzo.pambout
** File description:
** moves2
*/

#include "../include/sokoban.h"
#include "../include/my.h"

static void move_player_up(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y][position_x] =
        game_state_instance->initial_state[position_y][position_x];
    game_state_instance->position_y -= 1;
    game_state_instance->game_map[position_y - 1][position_x] = 'P';
}

static void move_box_up(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y - 1][position_x] = 'X';
}

void go_up(struct game_state *game_state_instance)
{
    int position_y = game_state_instance->position_y;
    int position_x = game_state_instance->position_x;
    char next_cell = game_state_instance->game_map[position_y - 1][position_x];
    char next_next_cell = game_state_instance->game_map[position_y - 2]
        [position_x];

    if (next_cell == 'X' && (next_next_cell == ' ' || next_next_cell == 'O')) {
        move_player_up(game_state_instance, position_y, position_x);
        move_box_up(game_state_instance, position_y - 1, position_x);
    } else if (next_cell == ' ' || next_cell == 'O') {
        move_player_up(game_state_instance, position_y, position_x);
    }
}

static void move_player_down(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y][position_x] =
        game_state_instance->initial_state[position_y][position_x];
    game_state_instance->position_y += 1;
    game_state_instance->game_map[position_y + 1][position_x] = 'P';
}

static void move_box_down(struct game_state *game_state_instance,
    int position_y, int position_x)
{
    game_state_instance->game_map[position_y + 1][position_x] = 'X';
}

void go_down(struct game_state *game_state_instance)
{
    int position_y = game_state_instance->position_y;
    int position_x = game_state_instance->position_x;
    char next_cell = game_state_instance->game_map[position_y + 1][position_x];
    char next_next_cell = game_state_instance->game_map[position_y + 2]
        [position_x];

    if (next_cell == 'X' && (next_next_cell == ' ' || next_next_cell == 'O')) {
        move_player_down(game_state_instance, position_y, position_x);
        move_box_down(game_state_instance, position_y + 1, position_x);
    } else if (next_cell == ' ' || next_cell == 'O') {
        move_player_down(game_state_instance, position_y, position_x);
    }
}
