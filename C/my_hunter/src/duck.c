/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** duck
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

float calculate_duck_velocity(Game *game)
{
    float difficultyMultiplier = 1.0f;

    switch (game->difficulty) {
        case EASY:
            difficultyMultiplier = 0.75f;
            break;
        case MEDIUM:
            difficultyMultiplier = 1.0f;
            break;
        case HARD:
            difficultyMultiplier = 1.5f;
            break;
    }
    return 100.0f + 60.0f * (game->level - 1) * difficultyMultiplier;
}

void handle_missed_duck(Game *game)
{
    game->missedDucks++;
    if (game->missedDucks >= 3) {
        display_defeat_screen(game);
        sfRenderWindow_close(game->window);
    } else {
        reset_duck(&game->duck);
    }
}

void update_duck_position(Game *game, float adjustedVelocity)
{
    game->duck.position.x += adjustedVelocity * game->deltaTime;
    if (game->duck.position.x > game->video_mode.width) {
        handle_missed_duck(game);
    }
}

void update_ducks(Game *game)
{
    float adjustedVelocity = calculate_duck_velocity(game);

    if (game->duck.isShot) {
        game->duck.position.y += 800.0f * game->deltaTime;
        if (game->duck.position.y > game->video_mode.height) {
            reset_duck(&game->duck);
        }
    } else {
        game->duck.position.x += adjustedVelocity * game->deltaTime;
        if (game->duck.position.x > game->video_mode.width) {
            handle_missed_duck(game);
        }
    }
    sfSprite_setPosition(game->duck.sprite, game->duck.position);
}

void reset_duck(Duck *duck)
{
    int minY = 100;
    int maxY = 500;

    duck->position.x = -duck->frameWidth;
    duck->position.y = (float)(rand() % (maxY - minY + 1)) + minY;
    duck->isShot = sfFalse;
    duck->velocity = 100.0f + (rand() % 50);
}
