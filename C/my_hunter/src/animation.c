/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** animation
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

void update_animation(Game *game)
{
    sfIntRect frameRect;

    game->duck.timeSinceLastFrame += game->deltaTime;
    if (game->duck.timeSinceLastFrame >= game->duck.animationSpeed) {
        game->duck.timeSinceLastFrame = 0.0f;
        game->duck.currentFrame = (game->duck.currentFrame + 1) %
            game->duck.frameCount;
        frameRect.left = game->duck.currentFrame * game->duck.frameWidth;
        frameRect.top = 0;
        frameRect.width = game->duck.frameWidth;
        frameRect.height = game->duck.frameHeight;
        sfSprite_setTextureRect(game->duck.sprite, frameRect);
    }
}

void set_duck_frame(Game *game, int frame)
{
    sfIntRect frameRect = {
        frame * game->duck.frameWidth,
        0,
        game->duck.frameWidth,
        game->duck.frameHeight
    };

    sfSprite_setTextureRect(game->duck.sprite, frameRect);
}
