/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** radar
*/

#include <SFML/Graphics.h>
#include "../include/building/simulation/sim.h"

#ifndef RADAR_H_
    #define RADAR_H_

int xyz_radar_launch_simulation(window_t *window, char const *script_path);
void xyz_radar_simulation_loop(sim_t *sim);
void xyz_radar_plane_loop(plane_t *plane, sim_t *sim, unsigned int c_time);
void xyz_radar_insert_planes_in_quadtree(plane_t **planes,
    quadtree_t *quadtree, unsigned int c_time);

#endif /* !RADAR_H_ */
