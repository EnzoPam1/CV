/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** endscreen
*/

#include <SFML/Graphics.h>
#include "game.h"

#ifndef ENDSCREEN_H_
    #define ENDSCREEN_H_

typedef struct EndScreenInfo {
    const char *message;
    sfColor color;
    sfText **messageText;
    sfText **scoreText;
    sfText **levelText;
} EndScreenInfo;

void display_victory_screen(Game *game);
void display_defeat_screen(Game *game);
void display_end_screen(Game *game, const char *message, sfColor color);
void prepare_end_screen_texts(Game *game, EndScreenInfo *info);
void render_end_screen(Game *game, sfText *messageText,
    sfText *scoreText, sfText *levelText);

#endif /* !ENDSCREEN_H_ */
