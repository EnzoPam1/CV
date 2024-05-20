/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim_texts
*/

#include <SFML/Graphics.h>
#include "../../building/window.h"
#include "sim_fonts.h"

#ifndef SIM_TEXTS_H_
    #define SIM_TEXTS_H_

typedef sfText text_t;

typedef struct sim_texts {
    text_t *timer;
} sim_texts_t;
typedef sim_texts_t texts_t;

sim_texts_t *xyz_texts_sim_texts_create(sim_fonts_t *fonts, window_t *window);
void xyz_texts_sim_texts_destroy(sim_texts_t *);

#endif /* !SIM_TEXTS_H_ */
