/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** collisions
*/

#include <SFML/Graphics.h>
#include "../include/building/simulation/sim.h"

#ifndef COLLISIONS_H_
    #define COLLISIONS_H_

plane_t *xyz_collisions_get_collided_plane(plane_t *plane, tower_t **towers,
    quadtree_t *quadtree);
sfBool xyz_collisions_plane_is_in_control_area(sfFloatRect hitbox,
    tower_t **towers);
plane_t *xyz_collisions_plane_check_collisions(plane_t *plane,
    quadtree_t *quadtree);

#endif /* !COLLISIONS_H_ */
