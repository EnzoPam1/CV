/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** main.c
*/

#include "my_navy.h"

global_signals_t *global_signals;

int check_file_existence(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        my_putstr("File doesn't exist !\n");
        return -1;
    }
    return fd;
}

void reset_global_state(void)
{
    global_signals->signal_str[0] = 'A';
    global_signals->signal_str[1] = '0';
    global_signals->feedback = 0;
}

int initialize_global_state(void)
{
    global_signals = malloc(sizeof(global_signals_t));
    global_signals->signal_state = 0;
    global_signals->signal_str = malloc(sizeof(char) * 3);
    global_signals->signal_str[0] = 'A';
    global_signals->signal_str[1] = '0';
    global_signals->signal_str[2] = 0;
    global_signals->feedback = 0;
    return 0;
}

static int handle_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help_message();
        return 1;
    }
    return 0;
}

static int start_game_according_to_player(int ac, game_status_t *status,
    char **av)
{
    if (ac == 2)
        return start_player_one_game(status);
    if (ac == 3)
        return start_player_two_game(status, av);
    return 84;
}

int start_game(int ac, char **av, game_status_t *status)
{
    int error;
    int ret;

    if (handle_help(ac, av))
        return 0;
    error = setup_game_structure(status, av, ac);
    if (error == 84)
        return 84;
    ret = start_game_according_to_player(ac, status, av);
    my_printf((ret == 0 ? "\nI Won\n" : "\nEnemy Won\n"));
    return ret;
}

int main(int ac, char **av)
{
    game_status_t status;
    int ret = initialize_global_state();

    if (ac < 2 || ac > 3)
        return 84;
    ret = start_game(ac, av, &status);
    return ret;
}
