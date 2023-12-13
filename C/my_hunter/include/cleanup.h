/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** cleanup
*/

#include "game.h"

#ifndef CLEANUP_H_
    #define CLEANUP_H_

void cleanup_clock(Game *game);
void cleanup_window(Game *game);
void cleanup_font(Game *game);
void cleanup_background(Game *game);
void cleanup_cursor(Game *game);

#endif /* !CLEANUP_H_ */
