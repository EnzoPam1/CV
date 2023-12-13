/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** duck
*/

#include "game.h"

#ifndef DUCK_H_
    #define DUCK_H_

float calculate_duck_velocity(Game *game);
void update_ducks(Game *game);
void reset_duck(Duck *duck);

#endif /* !DUCK_H_ */
