/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** player.c
*/

#include <stdbool.h>
#include "my_navy.h"

extern global_signals_t *global_signals;

void initiate_game(void)
{
    int pid = getpid();

    my_printf("my_pid: %d\nwaiting for enemy connexion...\n", pid);
    setup_signal_reception();
    my_printf("\nenemy connected\n\n");
}

static bool is_hit(game_status_t *status)
{
    unsigned int signal_char0 = (unsigned int)(global_signals->
        signal_str[0] - 'A');
    unsigned int signal_char1 = (unsigned int)(global_signals->
        signal_str[1] - '0' - 1);
    char map_char = status->player_map[signal_char1][signal_char0];

    return (map_char != '.' && map_char != 'o' && map_char != 'x');
}

static void handle_hit(game_status_t *status)
{
    usleep(100);
    kill(status->opponent_id, SIGUSR1);
    my_printf("hit\n\n");
    status->player_map[global_signals->signal_str[1] - '0' - 1]
        [global_signals->signal_str[0] - 'A'] = 'x';
}

void handle_miss(game_status_t *status)
{
    usleep(100);
    kill(status->opponent_id, SIGUSR2);
    my_printf("missed\n\n");
    if (status->player_map[global_signals->signal_str[1] - '0' - 1]
            [global_signals->signal_str[0] - 'A'] == '.')
        status->player_map[global_signals->signal_str[1] - '0' - 1]
            [global_signals->signal_str[0] - 'A'] = 'o';
}

void modify_game_status(game_status_t *status)
{
    if (global_signals->signal_str[1] == 0)
        global_signals->signal_str[1] += 1;
    if (is_hit(status)) {
        handle_hit(status);
    } else {
        handle_miss(status);
    }
}

int gameplay_loop_player_one(game_status_t *status)
{
    char *s;

    reset_global_state();
    display_full_game_status(status);
    s = verify_and_send(status);
    await_response();
    my_printf("%s: %s\n\n", s, determine_hit_or_miss(status, s));
    if (check_win_condition(status->opponent_map) == 14) {
        display_full_game_status(status);
        return (1);
    }
    my_printf("waiting for enemy's attack...\n");
    reset_global_state();
    receive_signal();
    my_printf("%s: ", global_signals->signal_str);
    modify_game_status(status);
    global_signals->signal_state = 0;
    global_signals->counter = 0;
    return (0);
}

int start_player_one_game(game_status_t *status)
{
    initiate_game();
    status->opponent_id = global_signals->parent_pid;
    while (check_win_condition(status->player_map) != 14 &&
        check_win_condition(status->opponent_map) != 14) {
        if (gameplay_loop_player_one(status) == 1)
            break;
    }
    display_full_game_status(status);
    return (check_win_condition(status->player_map) == 14 ? 1 : 0);
}
