/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** box_collisions
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "../../include/utils.h"

sfBool xyz_utils_boundary_contains_pos(sfIntRect const boundary,
    sfVector2f const pos)
{
    return (pos.x >= boundary.left &&
            pos.x < boundary.left + boundary.width &&
            pos.y >= boundary.top &&
            pos.y < boundary.top + boundary.height
    );
}

sfBool xyz_utils_boundary_overlaps(sfIntRect const boundary,
    sfIntRect const other)
{
    return !(
        other.left > boundary.left + boundary.width ||
        other.left + other.width < boundary.left ||
        other.top > boundary.top + boundary.height ||
        other.top + other.height < boundary.top
    );
}

sfBool xyz_utils_boundary_is_in_circle(sfFloatRect const frect,
    sfVector2f circle_center, unsigned int circle_radius)
{
    sfVector2f *frect_corners = xyz_utils_get_corners(frect);
    sfBool in_circle = sfFalse;

    for (unsigned int i = 0; i < 4 && !in_circle; i++)
        if (xyz_utils_point_is_in_circle(frect_corners[i], circle_center,
            circle_radius))
            in_circle = sfTrue;
    free(frect_corners);
    return (in_circle);
}

sfBool xyz_utils_point_is_in_circle(sfVector2f point,
    sfVector2f circle_center, unsigned int circle_radius)
{
    float x = point.x - circle_center.x;
    float y = point.y - circle_center.y;

    return (pow(x, 2) + pow(y, 2) <= pow(circle_radius, 2));
}
