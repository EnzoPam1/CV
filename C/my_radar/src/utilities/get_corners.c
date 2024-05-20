/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_utils_get_corners
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "utils.h"

sfVector2f *xyz_utils_get_corners(sfFloatRect const rect)
{
    sfVector2f *corners = malloc(sizeof(sfVector2f) * 4);

    if (!corners)
        return (NULL);
    corners[0] = (sfVector2f) {rect.left, rect.top};
    corners[1] = (sfVector2f) {rect.left + rect.width, rect.top};
    corners[2] = (sfVector2f) {rect.left, rect.top + rect.height};
    corners[3] = (sfVector2f) {rect.left + rect.width,
                                rect.top + rect.height};
    return (corners);
}

sfVector2f *xyz_utils_get_rotated_corners(sfFloatRect hitbox, float angle)
{
    sfVector2f center = {hitbox.left + hitbox.width / 2.0,
                        hitbox.top + hitbox.height / 2.0};
    sfVector2f *corners = xyz_utils_get_corners(hitbox);

    if (!corners)
        return (NULL);
    for (unsigned int i = 0; i < 4; i++)
        corners[i] = xyz_utils_get_rotated_point(corners[i], center, angle);
    return (corners);
}
