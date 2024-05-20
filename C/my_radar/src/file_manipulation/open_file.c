/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_file_get_entities_from_file
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/building/simulation/sim.h"
#include "../../include/building/plane.h"
#include "../../include/building/path.h"
#include "../../include/building/tower.h"
#include "../../include/file_manipulation.h"
#include "../../include/my.h"

int xyz_file_get_entities_from_file(char const *file_path, sim_t *sim)
{
    char *file_buffer = xyz_file_get_file_buffer(file_path);
    unsigned int nb_planes = 0;
    unsigned int nb_towers = 0;
    FILE *stream = NULL;

    if (!file_buffer)
        return (1);
    nb_planes = my_count_char(file_buffer, PLANE_SYMBOL);
    nb_towers = my_count_char(file_buffer, TOWER_SYMBOL);
    sim->planes = malloc(sizeof(plane_t *) * (nb_planes + 1));
    sim->towers = malloc(sizeof(tower_t *) * (nb_towers + 1));
    stream = fopen(file_path, "r");
    if (!(sim->planes) || !(sim->towers) || !(stream))
        return (1);
    if (xyz_file_fill_entities_by_line(stream, sim) != 0)
        return (1);
    fclose(stream);
    return (0);
}

static int process_plane_line(sim_t *sim, char *line, unsigned
    int *plane_index)
{
    plane_t *newPlane = xyz_file_add_plane_from_line(line,
        sim->textures->plane, sim->window->width);

    if (newPlane == NULL) {
        return 1;
    }
    sim->planes[*plane_index] = newPlane;
    (*plane_index)++;
    return 0;
}

static int process_tower_line(sim_t *sim, char *line, unsigned
    int *tower_index)
{
    tower_t *newTower = xyz_file_add_tower_from_line(line,
        sim->textures->tower);

    if (newTower == NULL) {
        return 1;
    }
    sim->towers[*tower_index] = newTower;
    (*tower_index)++;
    return 0;
}

static int process_line(sim_t *sim, char *line, unsigned int *plane_index,
    unsigned int *tower_index)
{
    if (line[0] == PLANE_SYMBOL) {
        return process_plane_line(sim, line, plane_index);
    } else if (line[0] == TOWER_SYMBOL) {
        return process_tower_line(sim, line, tower_index);
    } else {
        my_puterr("Unknown char in script file\n");
        return 1;
    }
}

int xyz_file_fill_entities_by_line(FILE *stream, sim_t *sim)
{
    char *current_line = NULL;
    long unsigned int size = 50;
    unsigned int plane_index = 0;
    unsigned int tower_index = 0;

    while (getline(&current_line, &size, stream) != -1) {
        if (process_line(sim, current_line, &plane_index, &tower_index) != 0) {
            return 1;
        }
    }
    sim->planes[plane_index] = NULL;
    sim->towers[tower_index] = NULL;
    return 0;
}

plane_t *xyz_file_add_plane_from_line(char *current_line,
    sfTexture *plane_texture, unsigned int w_width)
{
    path_t *path = NULL;
    sfVector2f departure;
    sfVector2f arrival;
    unsigned int speed = 0;
    unsigned int delay = 0;

    current_line++;
    departure.x = my_strtol(current_line, &current_line);
    departure.y = my_strtol(current_line, &current_line);
    arrival.x = my_strtol(current_line, &current_line);
    arrival.y = my_strtol(current_line, &current_line);
    speed = my_strtol(current_line, &current_line);
    delay = my_strtol(current_line, &current_line);
    path = xyz_path_path_create(departure, arrival, speed, w_width);
    if (path == NULL) {
        return (NULL);
    }
    return (xyz_airplane_plane_create(path, plane_texture, delay, w_width));
}

tower_t *xyz_file_add_tower_from_line(char *current_line,
    sfTexture *tower_texture)
{
    sfVector2f pos;
    unsigned int radius = 0;

    current_line++;
    pos.x = my_strtol(current_line, &current_line);
    pos.y = my_strtol(current_line, &current_line);
    radius = my_strtol(current_line, &current_line);
    return (xyz_tower_tower_create(pos, tower_texture, radius));
}
