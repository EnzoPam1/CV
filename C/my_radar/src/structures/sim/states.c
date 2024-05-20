/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim_states
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../../include/building/simulation/sim_states.h"

sim_states_t *xyz_states_sim_states_create(void)
{
    sim_states_t *states = malloc(sizeof(sim_states_t));

    if (!states)
        return (NULL);
    states->show_hitbox = sfTrue;
    states->show_sprites = sfTrue;
    return (states);
}

void xyz_states_sim_states_destroy(sim_states_t *states)
{
    if (states)
        free(states);
}
