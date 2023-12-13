/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** text_utils
*/

#include <SFML/Graphics.h>
#include "game.h"

#ifndef TEXT_UTILS_H_
    #define TEXT_UTILS_H_

sfText* create_centered_text(const char *str, sfFont* font,
    unsigned int characterSize, sfColor color);
void set_text_position(sfText* text, float x, float y);
sfText* generate_and_position_text(Game *game, TextInfo *textInfo);

#endif /* !TEXT_UTILS_H_ */
