/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** handle.c
*/

#include "my_navy.h"

extern global_signals_t *global_signals;

void process_signal(int signal, siginfo_t *si, void *context)
{
    (void)context;
    global_signals->parent_pid = si->si_pid;
    if (signal == SIGUSR1 && global_signals->signal_flag == 0)
        global_signals->signal_flag = 1;
    if (signal == SIGUSR1 && global_signals->signal_flag == 1)
        global_signals->signal_str[global_signals->counter]++;
    if (signal == SIGUSR2 && global_signals->counter != 2)
        global_signals->counter++;
    if (signal == SIGUSR2 && global_signals->counter == 2)
        global_signals->signal_state = 1;
}

void handle_signal_response(int signal, siginfo_t *si, void *context)
{
    (void)context;
    (void)si;
    if (signal == SIGUSR1)
        global_signals->feedback = 1;
    if (signal == SIGUSR2)
        global_signals->feedback = 2;
}

void setup_signal_reception(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_mask = mask;
    sa.sa_sigaction = process_signal;
    sa.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_printf("Error: cannot handle SIGUSR1\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_printf("Error: cannot handle SIGUSR2\n");
    while (global_signals->signal_flag == 0)
        usleep(100);
}

int await_response(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_mask = mask;
    sa.sa_sigaction = handle_signal_response;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_printf("Error: cannot handle SIGUSR1\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_printf("Error: cannot handle SIGUSR2\n");
    while (global_signals->feedback == 0)
        usleep(100);
    return (1);
}

int receive_signal(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_mask = mask;
    sa.sa_sigaction = process_signal;
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        my_printf("Error: cannot handle SIGUSR1\n");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        my_printf("Error: cannot handle SIGUSR2\n");
    while (global_signals->signal_state == 0)
        usleep(100);
    return (1);
}
