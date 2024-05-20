/*
** EPITECH PROJECT, 2023
** Sokoban Project
** File description:
** Main file for Sokoban Game
*/

#include "../include/sokoban.h"
#include "../include/my.h"

void my_panel(void)
{
    my_printf("USAGE\n\t\t./my_sokoban game_map\n\nDESCRIPTION\n");
    my_printf("\t\tmap\tfile representing the warehouse game_map, ");
    my_printf("containing '#' for walls,\n");
    my_putstr("'#' for walls,\n");
    my_printf("\t\t\t'P' for the player, 'X' for boxes and 'O' for ");
    my_putstr("storage locations.\n");
    exit(0);
}

void initialize_game(struct game_state *game_state_instance, char *file_path)
{
    game_state_instance->data_buffer = open_file(file_path);
    fill_struct(game_state_instance);
    check_game_map(game_state_instance);
}

void start_game(struct game_state *game_state_instance)
{
    initscr();
    noecho();
    curs_set(0);
    while (my_strlen(game_state_instance->game_map[0]) > COLS ||
            nb_line(game_state_instance->game_map) > LINES) {
        mvprintw(LINES / 2, (COLS / 2 - 6), "Resize");
        refresh();
    }
    clear();
    start_sokoban(game_state_instance);
}

int main(int ac, char **av)
{
    struct game_state game_state_instance;

    if (ac != 2) {
        return 84;
    }
    if (my_strcmp(av[1], "-h") == 0) {
        my_panel();
        return 0;
    }
    initialize_game(&game_state_instance, av[1]);
    start_game(&game_state_instance);
    return 0;
}
