/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-sokoban-enzo.pambout
** File description:
** main
*/

#include <stdlib.h>
#include <time.h>
#include "../include/radar.h"
#include "../include/usage.h"
#include "../include/events.h"
#include "../include/building/simulation/sim.h"
#include "../include/my.h"

int main(int ac, char **av)
{
    window_t *window = NULL;
    int exit_code = 0;

    exit_code = xyz_usage_check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (exit_code);
    srand(time(NULL));
    window = xyz_window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    if (window == NULL) {
        my_puterr("my_radar: Couldn't create window\n");
        return (MY_EXIT_FAILURE);
    }
    exit_code = xyz_radar_launch_simulation(window, av[1]);
    return (MY_EXIT_SUCCESS);
}
