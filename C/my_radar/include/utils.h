/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** utils
*/

#include <SFML/Graphics.h>

#ifndef UTILS_H_
    #define UTILS_H_

typedef unsigned int uint;

float xyz_utils_get_angle_from_coordinate(sfVector2f point_a,
    sfVector2f point_b);

sfVector2f xyz_utils_get_rotated_point(sfVector2f point, sfVector2f center,
    float angle);
sfVector2f *xyz_utils_get_corners(sfFloatRect const rect);
sfVector2f *xyz_utils_get_rotated_corners(sfFloatRect hitbox, float angle);
sfFloatRect xyz_utils_get_bounding_box_of_rotated(sfFloatRect const hitbox,
    float angle);
sfBool xyz_utils_pos_match(sfVector2f pos1, sfVector2f pos2);
sfBool xyz_utils_pos_are_near(sfVector2f pos1, sfVector2f pos2,
    float const threshold);
sfBool xyz_utils_boundary_contains_pos(sfIntRect const boundary,
    sfVector2f const pos);
sfBool xyz_utils_boundary_overlaps(sfIntRect const boundary,
    sfIntRect const other_boundary);
sfBool xyz_utils_boundary_is_in_circle(sfFloatRect const frect,
    sfVector2f circle_center, unsigned int circle_radius);
sfBool xyz_utils_point_is_in_circle(sfVector2f point, sfVector2f circle_center,
    unsigned int circle_radius);

#endif /* !UTILS_H_ */
