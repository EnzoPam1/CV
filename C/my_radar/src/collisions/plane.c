/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** plane_collisions
*/

#include <SFML/Graphics.h>
#include "../../include/building/simulation/sim.h"
#include "../../include/collisions.h"
#include "../../include/utils.h"

plane_t *xyz_collisions_get_collided_plane(plane_t *plane, tower_t **towers,
    quadtree_t *quadtree)
{
    if (xyz_collisions_plane_is_in_control_area(plane->hitbox, towers)) {
        sfRectangleShape_setOutlineColor(plane->outline, sfGreen);
        return (sfFalse);
    } else {
        sfRectangleShape_setOutlineColor(plane->outline, sfYellow);
    }
    return (xyz_collisions_plane_check_collisions(plane, quadtree));
}

sfBool xyz_collisions_plane_is_in_control_area(sfFloatRect hitbox,
    tower_t **towers)
{
    for (unsigned int i = 0; towers[i]; i++)
        if (xyz_utils_boundary_is_in_circle(hitbox, towers[i]->pos,
            towers[i]->radius))
            return (sfTrue);
    return (sfFalse);
}

plane_t *xyz_collisions_plane_check_collisions(plane_t *plane,
    quadtree_t *quadtree)
{
    sfIntRect area = (sfIntRect) {plane->path->pos.x - 30.0,
                                plane->path->pos.y - 30.0, 50, 50};
    plane_t **planes = xyz_quadtree_quadtree_query(quadtree, area);

    if (!planes)
        return (NULL);
    for (unsigned int i = 0; planes[i]; i++)
        if (!(xyz_utils_pos_match(plane->path->pos, planes[i]->path->pos)))
            return (planes[i]);
    return (NULL);
}
