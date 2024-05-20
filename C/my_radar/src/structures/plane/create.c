/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_airplane_plane_create
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../../include/radar.h"
#include "../../../include/building/plane.h"

plane_t *xyz_airplane_plane_create(path_t *path, sfTexture *texture,
    uint delay, uint w_width)
{
    plane_t *plane = malloc(sizeof(*plane));
    sfVector2f sprite_center = {PLANE_SPRITE_SIZE / 2, PLANE_SPRITE_SIZE / 2};

    if (!plane)
        return (NULL);
    plane->sprite = sfSprite_create();
    plane->outline = sfRectangleShape_create();
    if (!(plane->sprite) || !(plane->outline))
        return (NULL);
    sfSprite_setTexture(plane->sprite, texture, sfTrue);
    sfSprite_setOrigin(plane->sprite, sprite_center);
    sfRectangleShape_setFillColor(plane->outline, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->outline, sfYellow);
    sfRectangleShape_setOutlineThickness(plane->outline, 2.0);
    return (xyz_airplane_plane_init(plane, path, delay, w_width));
}

void xyz_airplane_plane_destroy(plane_t *plane)
{
    if (plane->path)
        free(plane->path);
    if (plane->sprite)
        sfSprite_destroy(plane->sprite);
    if (plane->outline)
        sfRectangleShape_destroy(plane->outline);
    if (plane)
        free(plane);
}
