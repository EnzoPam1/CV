/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** events
*/

#include <SFML/Graphics.h>
#include "../include/building/simulation/sim.h"

#ifndef EVENTS_H_
    #define EVENTS_H_

void xyz_events_sim_poll_events(sfRenderWindow *render, states_t *state);
void xyz_events_check_window_quit(sfEvent *event, sfRenderWindow *window);
void xyz_events_switch_pressed_key(sfEvent *event, states_t *states);

#endif /* !EVENTS_H_ */
