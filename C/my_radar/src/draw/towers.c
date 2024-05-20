/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_draw_towers
*/

#include <SFML/Graphics.h>
#include "../../include/building/tower.h"
#include "../../include/building/simulation/sim_states.h"

void xyz_draw_towers(sfRenderWindow *window, tower_t **towers,
    states_t *states)
{
    if (!(states->show_hitbox) && !(states->show_sprites))
        return;
    for (unsigned int i = 0; towers[i]; i++) {
        if (states->show_sprites)
            sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        if (states->show_hitbox)
            sfRenderWindow_drawCircleShape(window,
                                        towers[i]->control_area, NULL);
    }
}
