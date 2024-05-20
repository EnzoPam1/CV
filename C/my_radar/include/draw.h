/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** draw
*/

#include <SFML/Graphics.h>
#include "utils.h"
#include "./building/window.h"
#include "./building/plane.h"
#include "./building/tower.h"

#ifndef DRAW_H_
    #define DRAW_H_

void xyz_draw_background(sfRenderWindow *window, sfSprite *background);
void xyz_draw_timer(sfRenderWindow *window, text_t *timer_text, uint c_time);
void xyz_draw_plane(sfRenderWindow *render, plane_t *plane, states_t *states);
void xyz_draw_towers(sfRenderWindow *window, tower_t **towers,
    states_t *states);

#endif /* !DRAW_H_ */
