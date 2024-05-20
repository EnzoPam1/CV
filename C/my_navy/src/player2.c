/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** player2.c
*/

#include "my_navy.h"

extern global_signals_t *global_signals;

void initiate_alternate_game(void)
{
    int pid = getpid();

    my_printf("my_pid: %d\nsuccessfully connected\n\n", pid);
}

void modify_game_status_alternate(game_status_t *status)
{
    if (global_signals->signal_str[1] == 0)
        global_signals->signal_str[1] += 1;
    if (status->player_map[global_signals->signal_str[1] -
        '0' - 1][global_signals->signal_str[0] - 'A'] != '.' &&
        status->player_map[global_signals->signal_str[1] -
            '0' - 1][global_signals->signal_str[0] - 'A'] != 'o' &&
        status->player_map[global_signals->signal_str[1] -
            '0' - 1][global_signals->signal_str[0] - 'A'] != 'x') {
        kill(status->opponent_id, SIGUSR1);
        my_printf("%s: hit\n", global_signals->signal_str);
        status->player_map[global_signals->signal_str[1] -
            '0' - 1][global_signals->signal_str[0] - 'A'] = 'x';
    } else {
        kill(status->opponent_id, SIGUSR2);
        my_printf("%s: missed\n", global_signals->signal_str);
        if (status->player_map[global_signals->signal_str[1] -
            '0' - 1][global_signals->signal_str[0] - 'A'] == '.')
            status->player_map[global_signals->signal_str[1] -
                '0' - 1][global_signals->signal_str[0] - 'A'] = 'o';
    }
}

int gameplay_loop_player_two(game_status_t *status)
{
    char *s;

    reset_global_state();
    display_full_game_status(status);
    my_printf("waiting for enemy's attack...\n");
    receive_signal();
    modify_game_status_alternate(status);
    if (check_win_condition(status->player_map) == 14) {
        my_putchar('\n');
        display_full_game_status(status);
        return (1);
    }
    global_signals->signal_state = 0;
    global_signals->counter = 0;
    reset_global_state();
    s = verify_and_send(status);
    await_response();
    my_printf("%s: %s\n\n", s, determine_hit_or_miss(status, s));
    return (0);
}

int start_player_two_game(game_status_t *status, char **av)
{
    initiate_alternate_game();
    status->opponent_id = my_getnb(av[1]);
    kill(status->opponent_id, SIGUSR1);
    while (check_win_condition(status->player_map) != 14 &&
        check_win_condition(status->opponent_map) != 14) {
        if (gameplay_loop_player_two(status) == 1)
            break;
    }
    display_full_game_status(status);
    return (check_win_condition(status->player_map) == 14 ? 1 : 0);
}
