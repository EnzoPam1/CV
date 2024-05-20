/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** tower
*/

#include <SFML/Graphics.h>

#ifndef TOWER_H_
    #define TOWER_H_

    #define TOWER_SYMBOL            'T'

typedef struct tower {
    sfVector2f pos;
    unsigned int radius;
    sfSprite *sprite;
    sfCircleShape *control_area;
} tower_t;

tower_t *xyz_tower_tower_create(sfVector2f pos, sfTexture *texture,
    unsigned int radius);
void xyz_tower_tower_destroy(tower_t *tower);
sfVector2f xyz_tower_get_random_tower_pos(tower_t **towers);
sfBool xyz_tower_vector2f_match(sfVector2f pos_1, sfVector2f pos2);

#endif /* !TOWER_H_ */
