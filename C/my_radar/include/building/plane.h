/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** plane
*/

#include <SFML/Graphics.h>
#include "tower.h"
#include "path.h"
#include "utils.h"

#ifndef PLANE_H_
    #define PLANE_H_

    #define PLANE_SYMBOL 'A'
    #define PLANE_SPRITE_SIZE 20.0

typedef struct plane {
    path_t *path;
    unsigned int delay;
    float angle;
    sfFloatRect hitbox;
    sfSprite *sprite;
    sfRectangleShape *outline;
} plane_t;

plane_t *xyz_airplane_plane_create(path_t *path, sfTexture *texture,
    uint delay, uint w_width);
plane_t *xyz_airplane_plane_init(plane_t *plane, path_t *path, uint delay,
    uint w_width);
void xyz_airplane_plane_destroy(plane_t *plane);
void xyz_airplane_plane_move(plane_t *plane, sfVector2f const offset,
    uint w_width);
void xyz_airplane_plane_reset_random(plane_t *plane, tower_t **towers,
    uint c_time, uint w_width);

#endif /* !PLANE_H_ */
