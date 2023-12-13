/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** endscreen
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

static void handle_end_screen_events(Game *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

static void generate_score_text(Game *game, EndScreenInfo *info,
    TextInfo *textInfo, char *scoreStr)
{
    char scoreLabel[60] = "Score final : ";

    int_to_str(game->score, scoreStr);
    my_strcat(scoreLabel, scoreStr);
    textInfo->textContent = scoreLabel;
    textInfo->textSize = 30;
    textInfo->textColor = sfWhite;
    *(info->scoreText) = generate_and_position_text(game, textInfo);
}

static void generate_level_text(Game *game, EndScreenInfo *info,
    TextInfo *textInfo, char *levelStr)
{
    char levelLabel[60] = "Niveau atteint : ";

    int_to_str(game->level, levelStr);
    my_strcat(levelLabel, levelStr);
    textInfo->textContent = levelLabel;
    textInfo->textSize = 30;
    textInfo->textColor = sfWhite;
    *(info->levelText) = generate_and_position_text(game, textInfo);
}

void prepare_end_screen_texts(Game *game, EndScreenInfo *info)
{
    char scoreStr[50];
    char levelStr[50];
    float yOffset = 30.0f;
    TextInfo textInfo;

    textInfo.yOffset = &yOffset;
    textInfo.textContent = info->message;
    textInfo.textSize = 50;
    textInfo.textColor = info->color;
    *(info->messageText) = generate_and_position_text(game, &textInfo);
    generate_score_text(game, info, &textInfo, scoreStr);
    generate_level_text(game, info, &textInfo, levelStr);
}

void render_end_screen(Game *game, sfText *messageText, sfText *scoreText,
    sfText *levelText)
{
    while (sfRenderWindow_isOpen(game->window)) {
        handle_end_screen_events(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawText(game->window, messageText, NULL);
        sfRenderWindow_drawText(game->window, scoreText, NULL);
        sfRenderWindow_drawText(game->window, levelText, NULL);
        sfRenderWindow_display(game->window);
    }
}

void display_end_screen(Game *game, const char *message, sfColor color)
{
    EndScreenInfo info;
    sfText *messageText;
    sfText *scoreText;
    sfText *levelText;

    info.message = message;
    info.color = color;
    info.messageText = &messageText;
    info.scoreText = &scoreText;
    info.levelText = &levelText;
    prepare_end_screen_texts(game, &info);
    render_end_screen(game, messageText, scoreText, levelText);
    sfText_destroy(messageText);
    sfText_destroy(scoreText);
    sfText_destroy(levelText);
}

void display_victory_screen(Game *game)
{
    display_end_screen(game, "Victoire !", sfGreen);
}

void display_defeat_screen(Game *game)
{
    display_end_screen(game, "Defaite !", sfRed);
}
