/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_airplane_plane_move
*/

#include <SFML/Graphics.h>
#include "../../../include/building/plane.h"

static void xyz_airplane_plane_move_out_of_bounds(plane_t *plane, uint w_width)
{
    sfVector2f offset = {(float)w_width, 0.0};

    if (plane->path->pos.x > w_width)
        offset.x = -offset.x;
    xyz_airplane_plane_move(plane, offset, w_width);
}

void xyz_airplane_plane_move(plane_t *plane, sfVector2f const offset,
    uint w_width)
{
    plane->path->pos.x += offset.x;
    plane->path->pos.y += offset.y;
    plane->hitbox.left += offset.x;
    plane->hitbox.top += offset.y;
    sfSprite_move(plane->sprite, offset);
    sfRectangleShape_setPosition(plane->outline, (sfVector2f)
                                {plane->hitbox.left, plane->hitbox.top});
    if (plane->path->pos.x < 0 || plane->path->pos.x > w_width)
        xyz_airplane_plane_move_out_of_bounds(plane, w_width);
}
