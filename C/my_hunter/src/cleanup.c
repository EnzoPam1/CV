/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** cleanup
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../include/game.h"
#include "../include/events.h"
#include "../include/graphics.h"
#include "../include/duck.h"
#include "../include/animation.h"
#include "../include/init.h"
#include "../include/cleanup.h"
#include "../include/endscreen.h"
#include "../include/text_utils.h"
#include "../include/duck_init.h"
#include "../include/my.h"

void cleanup_clock(Game *game)
{
    if (game->clock) {
        sfClock_destroy(game->clock);
    }
}

void cleanup_window(Game *game)
{
    if (game->window) {
        sfRenderWindow_destroy(game->window);
    }
}

void cleanup_font(Game *game)
{
    if (game->font) {
        sfFont_destroy(game->font);
    }
}

void cleanup_background(Game *game)
{
    if (game->backgroundSprite) {
        sfSprite_destroy(game->backgroundSprite);
    }
    if (game->backgroundTexture) {
        sfTexture_destroy(game->backgroundTexture);
    }
}

void cleanup_cursor(Game *game)
{
    if (game->cursorSprite) {
        sfSprite_destroy(game->cursorSprite);
    }
    if (game->cursorTexture) {
        sfTexture_destroy(game->cursorTexture);
    }
}
