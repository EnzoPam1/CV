/*
** EPITECH PROJECT, 2023
** Sokoban Project
** File description:
** Check for win/lose conditions in Sokoban Game
*/

#include "../include/sokoban.h"
#include "../include/my.h"

static int count_goal_positions_on_line(char *initial_state_line,
    char *game_map_line)
{
    int position_x = 0;
    int cpt = 0;

    for (position_x = 0; initial_state_line[position_x]; position_x++) {
        if (game_map_line[position_x] == 'O') {
            cpt++;
        }
    }
    return cpt;
}

static int count_goal_positions(struct game_state *game_state_instance)
{
    int position_y = 0;
    int cpt = 0;

    for (position_y = 0; game_state_instance->initial_state
        [position_y] != NULL; position_y++) {
        cpt += count_goal_positions_on_line(game_state_instance->initial_state
            [position_y], game_state_instance->game_map[position_y]);
    }
    return cpt;
}

int check_win(struct game_state *game_state_instance)
{
    int cpt = count_goal_positions(game_state_instance);

    return (game_state_instance->initial_state[game_state_instance->position_y]
        [game_state_instance->position_x] == 'O') ? cpt + 1 : cpt;
}

static int check_if_blocked(char **tab, int position_y, int position_x)
{
    return ((tab[position_y][position_x + 1] == '#' && (tab[position_y - 1]
        [position_x] == '#' || tab[position_y + 1][position_x] == '#')) ||
            (tab[position_y][position_x - 1] == '#' && (tab[position_y - 1]
                [position_x] == '#' || tab[position_y + 1]
                    [position_x] == '#')));
}

static void process_box(char **tab, int y, int x, BoxParams *params)
{
    if (tab[y][x] == 'X') {
        (*(params->nb))++;
        *(params->er) += check_if_blocked(tab, y, x) ? 1 : 0;
    }
}

static void calculate_blocks_and_boxes(char **tab, int *er, int *nb)
{
    int position_y;
    int position_x;
    BoxParams params = {er, nb};

    for (position_y = 0; tab[position_y] != NULL; position_y++) {
        for (position_x = 0; tab[position_y][position_x]; position_x++) {
            process_box(tab, position_y, position_x, &params);
        }
    }
}

int check_loose(char **tab)
{
    int er = 0;
    int nb = 0;

    calculate_blocks_and_boxes(tab, &er, &nb);
    return (er == nb) ? 0 : 84;
}

static void update_count(char c, int *nb_x, int *nb_o, int *nb_p)
{
    switch (c) {
        case 'X':
            (*nb_x)++;
            break;
        case 'O':
            (*nb_o)++;
            break;
        case 'P':
            (*nb_p)++;
            break;
        default:
            if (c != '#' && c != ' ' && c != '\n') {
                exit(84);
            }
    }
}

void check_game_map(struct game_state *game_state_instance)
{
    int i = 0;
    int nb_x = 0;
    int nb_o = 0;
    int nb_p = 0;

    while (game_state_instance->data_buffer[i]) {
        update_count(game_state_instance->data_buffer[i],
            &nb_x, &nb_o, &nb_p);
        i++;
    }
    if (nb_x < nb_o || nb_x == 0 || nb_o == 0 || nb_p != 1) {
        exit(84);
    }
}

int nb_line(char **tab)
{
    int position_y = 0;

    while (tab[position_y]) {
        position_y++;
    }
    return position_y - 1;
}
