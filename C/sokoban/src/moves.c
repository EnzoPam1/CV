/*
** EPITECH PROJECT, 2023
** Sokoban Project
** File description:
** Player movement functions for Sokoban Game
*/

#include "../include/sokoban.h"
#include "../include/my.h"

static void handle_right_input(struct game_state *game_state_instance)
{
    if (game_state_instance->game_map[game_state_instance->position_y]
        [game_state_instance->position_x + 1] != '#') {
        go_right(game_state_instance);
    }
}

static void handle_left_input(struct game_state *game_state_instance)
{
    if (game_state_instance->game_map[game_state_instance->position_y]
        [game_state_instance->position_x - 1] != '#') {
        go_left(game_state_instance);
    }
}

static void handle_up_input(struct game_state *game_state_instance)
{
    if (game_state_instance->game_map[game_state_instance->position_y - 1]
        [game_state_instance->position_x] != '#') {
        go_up(game_state_instance);
    }
}

static void handle_down_input(struct game_state *game_state_instance)
{
    if (game_state_instance->game_map[game_state_instance->position_y + 1]
        [game_state_instance->position_x] != '#') {
        go_down(game_state_instance);
    }
}

static void handle_direction_input(struct game_state *game_state_instance,
    int input)
{
    switch (input) {
        case RIGHT:
            handle_right_input(game_state_instance);
            break;
        case LEFT:
            handle_left_input(game_state_instance);
            break;
        case UP:
            handle_up_input(game_state_instance);
            break;
        case DOWN:
            handle_down_input(game_state_instance);
            break;
        default:
            break;
    }
}

static void reset_game_map_if_space(struct game_state *game_state_instance,
    int input)
{
    if (input == SPACE) {
        game_state_instance->game_map =
            my_str_to_word_array(game_state_instance->data_buffer, "\n");
        game_state_instance->position_y = game_state_instance->saveposition_y;
        game_state_instance->position_x = game_state_instance->saveposition_x;
    }
}

void moves(struct game_state *game_state_instance, int input)
{
    handle_direction_input(game_state_instance, input);
    reset_game_map_if_space(game_state_instance, input);
}
