/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** init
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

int init_font(Game *game)
{
    game->font = sfFont_createFromFile("./fonts/1.ttf");
    if (!game->font) {
        my_putstr("Erreur lors du chargement de la police.\n");
        return 0;
    }
    return 1;
}

int init_window(Game *game)
{
    game->video_mode = (sfVideoMode){800, 600, 32};
    game->window = sfRenderWindow_create(game->video_mode,
        "My Hunter", sfResize | sfClose, NULL);
    if (!game->window) {
        my_putstr("Erreur lors de la création de la fenêtre.\n");
        return 0;
    }
    return 1;
}

int init_cursor(Game *game)
{
    sfVector2u textureSize;

    game->cursorTexture = sfTexture_createFromFile
        ("ressources/viseur.png", NULL);
    if (!game->cursorTexture) {
        return 0;
    }
    game->cursorSprite = sfSprite_create();
    if (!game->cursorSprite) {
        sfTexture_destroy(game->cursorTexture);
        return 0;
    }
    sfSprite_setTexture(game->cursorSprite, game->cursorTexture, sfTrue);
    textureSize = sfTexture_getSize(game->cursorTexture);
    sfSprite_setOrigin(game->cursorSprite, (sfVector2f)
        {textureSize.x / 2, textureSize.y / 2});
    sfSprite_setScale(game->cursorSprite, (sfVector2f){0.2f, 0.2f});
    return 1;
}

int init_clock(Game *game)
{
    game->clock = sfClock_create();
    if (!game->clock) {
        return 0;
    }
    return 1;
}

int init_background(Game *game)
{
    game->backgroundTexture = sfTexture_createFromFile
        ("./ressources/back.jpg", NULL);
    if (!game->backgroundTexture) {
        return 0;
    }
    game->backgroundSprite = sfSprite_create();
    if (!game->backgroundSprite) {
        sfTexture_destroy(game->backgroundTexture);
        return 0;
    }
    sfSprite_setTexture(game->backgroundSprite, game->backgroundTexture,
        sfTrue);
    return 1;
}
