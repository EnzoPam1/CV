/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim
*/

#include <stdlib.h>
#include <SFML/System.h>
#include "../../../include/building/simulation/sim.h"
#include "../../../include/file_manipulation.h"
#include "../../../include/building/window.h"
#include "../../../include/building/plane.h"
#include "../../../include/building/tower.h"

sim_t *xyz_sim_sim_create(window_t *window)
{
    sim_t *sim = malloc(sizeof(sim_t));

    if (!sim)
        return (NULL);
    sim->window = window;
    sim->textures = xyz_textures_sim_textures_create();
    sim->fonts = xyz_fonts_sim_fonts_create();
    sim->state = xyz_states_sim_states_create();
    sim->clock = sfClock_create();
    sim->texts = xyz_texts_sim_texts_create(sim->fonts, sim->window);
    sim->quadtree = xyz_quadtree_quadtree_create((sfIntRect) {0, 0,
                                    sim->window->width, sim->window->height});
    sim->planes = NULL;
    sim->towers = NULL;
    if (!(sim->textures) || !(sim->fonts) || !(sim->state) || !(sim->texts))
        return (NULL);
    if (!(sim->quadtree) || !(sim->clock))
        return (NULL);
    return (sim);
}

sim_t *xyz_sim_sim_create_from_script(window_t *window,
    char const *script_path)
{
    sim_t *sim = xyz_sim_sim_create(window);

    if (!sim)
        return (NULL);
    if (xyz_file_get_entities_from_file(script_path, sim) != 0)
        return (NULL);
    return (sim);
}

void xyz_sim_sim_destroy(sim_t *sim)
{
    xyz_window_destroy(sim->window);
    sfClock_destroy(sim->clock);
    xyz_textures_sim_textures_destroy(sim->textures);
    xyz_fonts_sim_fonts_destroy(sim->fonts);
    xyz_texts_sim_texts_destroy(sim->texts);
    xyz_states_sim_states_destroy(sim->state);
    for (unsigned int i = 0; sim->towers[i]; i++)
        xyz_tower_tower_destroy(sim->towers[i]);
    for (unsigned int i = 0; sim->planes[i]; i++)
        xyz_airplane_plane_destroy(sim->planes[i]);
    if (sim->quadtree) {
        xyz_quadtree_quadtree_clear(sim->quadtree);
        free(sim->quadtree);
    }
    if (sim)
        free(sim);
}
