/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** duck_init
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
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

void initialize_duck_texture_and_sprite(Game *game)
{
    sfIntRect frameRect = {0, 0, game->duck.frameWidth,
        game->duck.frameHeight};

    game->duck.texture = sfTexture_createFromFile
        ("./ressources/coincoin.png", NULL);
    if (!game->duck.texture) {
        my_putstr("Erreur lors du chargement de la texture du canard.\n");
        return;
    }
    game->duck.sprite = sfSprite_create();
    if (!game->duck.sprite) {
        sfTexture_destroy(game->duck.texture);
        my_putstr("Erreur lors de la création du sprite du canard.\n");
        return;
    }
    sfSprite_setTexture(game->duck.sprite, game->duck.texture, sfTrue);
    sfSprite_setTextureRect(game->duck.sprite, frameRect);
    sfSprite_setPosition(game->duck.sprite, game->duck.position);
}

void initialize_ducks(Game *game)
{
    game->duck.position = (sfVector2f){-110, 250.0f};
    game->duck.velocity = 100.0f;
    game->duck.frameCount = 3;
    game->duck.currentFrame = 0;
    game->duck.timeSinceLastFrame = 0.0f;
    game->duck.animationSpeed = 0.25f;
    game->duck.frameWidth = 110;
    game->duck.frameHeight = 110;
    game->duck.isShot = sfFalse;
    initialize_duck_texture_and_sprite(game);
}
