/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** graphics
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <string.h>
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

static void load_duck_texture(Game *game)
{
    game->duck.texture = sfTexture_createFromFile("./ressources/coincoin.png",
        NULL);
    if (!game->duck.texture) {
        my_putstr("Erreur lors du chargement de la texture du canard.\n");
    }
}

static void create_duck_sprite(Game *game)
{
    if (!game->duck.texture) {
        return;
    }
    game->duck.sprite = sfSprite_create();
    if (!game->duck.sprite) {
        sfTexture_destroy(game->duck.texture);
        my_putstr("Erreur lors de la création du sprite du canard.\n");
    }
}

void initialize_graphics(Game *game)
{
    sfIntRect frameRect;

    load_duck_texture(game);
    create_duck_sprite(game);
    if (!game->duck.sprite) {
        return;
    }
    sfSprite_setTexture(game->duck.sprite, game->duck.texture, sfTrue);
    frameRect = (sfIntRect){0, 0, game->duck.frameWidth,
        game->duck.frameHeight};
    sfSprite_setTextureRect(game->duck.sprite, frameRect);
    sfSprite_setPosition(game->duck.sprite, game->duck.position);
}

void draw_ducks(Game *game)
{
    sfRenderWindow_drawSprite(game->window, game->duck.sprite, NULL);
}

static sfText* create_text(const char *label, const sfFont* font,
    sfVector2f position)
{
    sfText* text = sfText_create();

    sfText_setString(text, label);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setFillColor(text, sfWhite);
    sfText_setPosition(text, position);
    return text;
}

void draw_score(Game *game)
{
    char scoreStr[50];
    char scoreLabel[60] = "Score: ";
    sfText* text;

    int_to_str(game->score, scoreStr);
    my_strcat(scoreLabel, scoreStr);
    text = create_text(scoreLabel, game->font, (sfVector2f){10, 10});
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void draw_level(Game *game)
{
    char levelStr[50];
    char levelLabel[60] = "Level: ";
    sfText* levelText;

    int_to_str(game->level, levelStr);
    my_strcat(levelLabel, levelStr);
    levelText = create_text(levelLabel, game->font, (sfVector2f){10, 50});
    sfRenderWindow_drawText(game->window, levelText, NULL);
    sfText_destroy(levelText);
}
