/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** path
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "../../include/building/path.h"
#include "../../include/utils.h"

path_t *xyz_path_path_create(sfVector2f beg, sfVector2f end,
    uint speed, uint w_width)
{
    path_t *path = malloc(sizeof(*path));
    sfVector2f alt_pos = beg;

    if (!path)
        return (NULL);
    alt_pos.x += (beg.x < end.x) ? (int)w_width : -((int)w_width);
    path->pos = beg;
    path->end = end;
    if (fabs(end.x - beg.x) <= fabs(end.x - alt_pos.x))
        path->step = xyz_path_get_step_offset(beg, end);
    else
        path->step = xyz_path_get_step_offset(alt_pos, end);
    path->step.x *= speed;
    path->step.y *= speed;
    return (path);
}

sfVector2f xyz_path_get_step_offset(sfVector2f point_a, sfVector2f point_b)
{
    int dx = point_b.x - point_a.x;
    int dy = point_b.y - point_a.y;
    unsigned int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    sfVector2f offset;

    offset.x = dx / (float)steps;
    offset.y = dy / (float)steps;
    return (offset);
}

path_t *xyz_path_get_random_path(tower_t **towers, uint w_width)
{
    sfVector2f beg;
    sfVector2f end;
    unsigned int speed = rand() % (6 + 1 - 3) + 3;

    beg = xyz_tower_get_random_tower_pos(towers);
    end = xyz_tower_get_random_tower_pos(towers);
    while (xyz_utils_pos_match(beg, end))
        end = xyz_tower_get_random_tower_pos(towers);
    return (xyz_path_path_create(beg, end, speed, w_width));
}
