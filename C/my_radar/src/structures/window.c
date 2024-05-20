/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** window
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../include/building/window.h"

window_t *xyz_window_create(unsigned int width, unsigned int height,
    char const *window_title)
{
    window_t *window = malloc(sizeof(*window));
    sfVideoMode mode = {width, height, W_BPP};

    if (!window)
        return (NULL);
    window->render = sfRenderWindow_create(mode, window_title,
                                        sfClose | sfFullscreen, NULL);
    window->width = width;
    window->height = height;
    window->background = NULL;
    sfRenderWindow_setFramerateLimit(window->render, W_MAX_FPS);
    return (window);
}

void xyz_window_destroy(window_t *window)
{
    sfRenderWindow_destroy(window->render);
    if (window->background)
        sfSprite_destroy(window->background);
    if (window)
        free(window);
}

void xyz_window_set_background(window_t *window, sfTexture *texture)
{
    if (!(window->background))
        window->background = sfSprite_create();
    sfSprite_setTexture(window->background, texture, sfTrue);
}
