/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** text_utils
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

sfText* create_centered_text(const char *str, sfFont* font,
    unsigned int characterSize, sfColor color)
{
    sfText* text;

    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, characterSize);
    sfText_setFillColor(text, color);
    return text;
}

void set_text_position(sfText* text, float x, float y)
{
    sfFloatRect bounds = sfText_getGlobalBounds(text);

    sfText_setPosition(text, (sfVector2f){x - bounds.width / 2.0f, y});
}

sfText* generate_and_position_text(Game *game, TextInfo *textInfo)
{
    sfVector2u windowSize = sfRenderWindow_getSize(game->window);
    sfText* text = create_centered_text(textInfo->textContent, game->font,
        textInfo->textSize, textInfo->textColor);

    set_text_position(text, windowSize.x / 2.0f, *(textInfo->yOffset));
    *(textInfo->yOffset) += sfText_getGlobalBounds(text).height + 15.0f;
    return text;
}
