/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** window
*/

#include <SFML/Graphics.h>

#ifndef WINDOW_H_
    #define WINDOW_H_

    #define W_WIDTH         1920
    #define W_HEIGHT        1080
    #define W_BPP           32
    #define W_MAX_FPS       30
    #define W_TITLE         "my_radar"

typedef struct window {
    sfRenderWindow *render;
    unsigned int width;
    unsigned int height;
    sfSprite *background;
} window_t;

window_t *xyz_window_create(unsigned int width, unsigned int height,
    char const *window_title);
void xyz_window_destroy(window_t *window);
void xyz_window_set_background(window_t *window, sfTexture *texture);

#endif /* !WINDOW_H_ */
