/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_draw_plane
*/

#include <SFML/Graphics.h>
#include "../../include/building/plane.h"
#include "../../include/building/simulation/sim_states.h"

void xyz_draw_plane(sfRenderWindow *render, plane_t *plane, states_t *states)
{
    if (states->show_sprites)
        sfRenderWindow_drawSprite(render, plane->sprite, NULL);
    if (states->show_hitbox)
        sfRenderWindow_drawRectangleShape(render, plane->outline, NULL);
}
