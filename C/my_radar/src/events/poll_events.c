/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** poll_events
*/

#include <SFML/Graphics.h>
#include "../../include/events.h"
#include "../../include/draw.h"
#include "../../include/building/simulation/sim.h"

void xyz_events_sim_poll_events(sfRenderWindow *render, states_t *state)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(render, &event)) {
        xyz_events_check_window_quit(&event, render);
        if (event.type == sfEvtKeyReleased)
            xyz_events_switch_pressed_key(&event, state);
    }
}

void xyz_events_check_window_quit(sfEvent *event, sfRenderWindow *window)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
        sfRenderWindow_close(window);
}

void xyz_events_switch_pressed_key(sfEvent *event, states_t *states)
{
    switch (event->key.code) {
    case sfKeyL:
        states->show_hitbox = (states->show_hitbox) ? sfFalse : sfTrue;
        break;
    case sfKeyS:
        states->show_sprites = (states->show_sprites) ? sfFalse : sfTrue;
        break;
    default:
        break;
    }
}
