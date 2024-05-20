/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_draw_background
*/

#include <SFML/Graphics.h>

void xyz_draw_background(sfRenderWindow *window, sfSprite *background)
{
    sfRenderWindow_drawSprite(window, background, NULL);
}
