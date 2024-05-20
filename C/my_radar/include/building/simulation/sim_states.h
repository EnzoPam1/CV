/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim_states
*/

#include <SFML/Graphics.h>

#ifndef SIM_STATES_H_
    #define SIM_STATES_H_

typedef sfBool Bool;

typedef struct sim_states {
    Bool show_hitbox;
    Bool show_sprites;
    Bool is_paused;
} sim_states_t;
typedef sim_states_t states_t;

sim_states_t *xyz_states_sim_states_create(void);
void xyz_states_sim_states_destroy(sim_states_t *);

#endif /* !SIM_STATES_H_ */
