/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** simulation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../include/radar.h"
#include "../include/usage.h"
#include "../include/draw.h"
#include "../include/events.h"
#include "../include/utils.h"
#include "../include/collisions.h"
#include "../include/building/simulation/sim.h"
#include "../include/building/quadtree.h"
#include "../include/building/plane.h"
#include "../include/my.h"

int xyz_radar_launch_simulation(window_t *window, char const *script_path)
{
    sim_t *sim = NULL;

    sim = xyz_sim_sim_create_from_script(window, script_path);
    if (sim == NULL) {
        my_puterr("Simulation couldn't be created.\n");
        return (MY_EXIT_FAILURE);
    }
    xyz_window_set_background(sim->window, sim->textures->sim_bg);
    sfClock_restart(sim->clock);
    while (sfRenderWindow_isOpen(sim->window->render)) {
        xyz_events_sim_poll_events(sim->window->render, sim->state);
        sfRenderWindow_clear(sim->window->render, sfWhite);
        xyz_radar_simulation_loop(sim);
        sfRenderWindow_display(sim->window->render);
    }
    xyz_sim_sim_destroy(sim);
    return (MY_EXIT_SUCCESS);
}

void xyz_radar_simulation_loop(sim_t *sim)
{
    uint c_time = sfTime_asSeconds(sfClock_getElapsedTime(sim->clock));

    xyz_quadtree_quadtree_clear(sim->quadtree);
    xyz_radar_insert_planes_in_quadtree(sim->planes, sim->quadtree, c_time);
    xyz_draw_background(sim->window->render, sim->window->background);
    xyz_draw_towers(sim->window->render, sim->towers, sim->state);
    for (unsigned int i = 0; sim->planes[i]; i++)
        xyz_radar_plane_loop(sim->planes[i], sim, c_time);
    xyz_draw_timer(sim->window->render, sim->texts->timer, c_time);
}

void xyz_radar_plane_loop(plane_t *plane, sim_t *sim, uint c_time)
{
    plane_t *coll_plane = NULL;

    if (plane->delay > c_time)
        return;
    coll_plane = xyz_collisions_get_collided_plane(plane, sim->towers,
        sim->quadtree);
    if (coll_plane) {
        xyz_airplane_plane_reset_random(plane, sim->towers, c_time,
            sim->window->width);
        xyz_airplane_plane_reset_random(coll_plane, sim->towers, c_time,
            sim->window->width);
        return;
    }
    xyz_draw_plane(sim->window->render, plane, sim->state);
    xyz_airplane_plane_move(plane, plane->path->step, sim->window->width);
    if (xyz_utils_pos_are_near(plane->path->pos, plane->path->end, 10.0))
        xyz_airplane_plane_reset_random(plane, sim->towers, c_time,
            sim->window->width);
}

void xyz_radar_insert_planes_in_quadtree(plane_t **planes,
    quadtree_t *quadtree, uint c_time)
{
    for (unsigned int i = 0; planes[i]; i++)
        if (planes[i]->delay <= c_time)
            xyz_quadtree_quadtree_insert(quadtree, planes[i]);
}
