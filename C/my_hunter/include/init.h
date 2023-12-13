/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** init
*/

#include <SFML/Graphics.h>
#include "game.h"

#ifndef INIT_H_
    #define INIT_H_

int init_font(Game *game);
int init_window(Game *game);
int init_cursor(Game *game);
int init_clock(Game *game);
int init_background(Game *game);

#endif /* !INIT_H_ */
