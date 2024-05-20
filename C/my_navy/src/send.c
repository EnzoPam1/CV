/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** send.c
*/

#include "my_navy.h"

extern global_signals_t *global_signals;

int send_signal_data(int nb1, int nb2, int pid)
{
    int i;

    i = 0;
    while (i != nb1) {
        kill(pid, SIGUSR1);
        usleep(100);
        i++;
    }
    kill(pid, SIGUSR2);
    i = 0;
    while (i != nb2) {
        kill(pid, SIGUSR1);
        usleep(100);
        i++;
    }
    kill(pid, SIGUSR2);
    return (1);
}

char *determine_hit_or_miss(game_status_t *status, char *s)
{
    char *hit = "hit";
    char *miss = "missed";

    if (global_signals->feedback == 1)
        status->opponent_map[s[1] - '0' - 1][s[0] - 'A'] = 'x';
    else {
        if (status->opponent_map[s[1] - '0' - 1][s[0] - 'A'] != 'x')
            status->opponent_map[s[1] - '0' - 1][s[0] - 'A'] = 'o';
    }
    return (global_signals->feedback == 1 ? hit : miss);
}

char *verify_and_send(game_status_t *status)
{
    char *s;
    int ok = 0;

    while (ok != 1) {
        my_printf("\nattack: ");
        s = read_next_line(0);
        if (my_strlen(s) == 2 && s[0] >= 'A' &&
            s[0] <= 'H' && s[1] >= '1' && s[1] <= '8')
            ok = 1;
        else
            my_printf("wrong position");
    }
    send_signal_data(s[0] - 'A', s[1] - 48, status->opponent_id);
    return (s);
}
