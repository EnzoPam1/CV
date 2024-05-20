/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim
*/

#include <SFML/Graphics.h>
#include "../../building/window.h"
#include "../../building/quadtree.h"
#include "../../building/plane.h"
#include "../../building/tower.h"
#include "sim_textures.h"
#include "sim_fonts.h"
#include "sim_texts.h"
#include "sim_states.h"

#ifndef SIM_H_
    #define SIM_H_

typedef struct simulation {
    window_t *window;
    quadtree_t *quadtree;
    plane_t **planes;
    tower_t **towers;
    textures_t *textures;
    fonts_t *fonts;
    texts_t *texts;
    states_t *state;
    sfClock *clock;
} sim_t;

sim_t *xyz_sim_sim_create(window_t *window);
sim_t *xyz_sim_sim_create_from_script(window_t *window, char const *filepath);
void xyz_sim_sim_destroy(sim_t *sim);

#endif /* !SIM_H_ */
