/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** event
*/

#include <SFML/Graphics.h>
#include "game.h"

#ifndef EVENT_H_
    #define EVENT_H_

typedef struct {
    const char *textContent;
    unsigned int textSize;
    sfColor textColor;
    float *yOffset;
} TextInfo;

void handle_key_event(Game *game, sfKeyEvent keyEvent);
void handle_mouse_or_resize_event(Game *game, sfEvent event);
void handle_other_event(Game *game, sfEvent event);
void handle_events(Game *game);
void check_duck_shot(Game *game, int mouse_x, int mouse_y);

#endif /* !EVENT_H_ */
