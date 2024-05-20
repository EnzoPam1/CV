/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** file_manipulation
*/

#include <stdio.h>
#include <SFML/Graphics.h>
#include "sim.h"
#include "plane.h"
#include "tower.h"

#ifndef FILE_MANIPULATION_H_
    #define FILE_MANIPULATION_H_

    #define OPEN_FAILURE_MSG        "File cannot be opened\n"
    #define READ_FAILURE_MSG        "File cannot be read\n"

char *xyz_file_get_file_buffer(char const *file_path);
unsigned int xyz_file_get_file_size(char const *file_path);

int xyz_file_get_entities_from_file(char const *file_path, sim_t *sim);
int xyz_file_fill_entities_by_line(FILE *stream, sim_t *sim);
plane_t *xyz_file_add_plane_from_line(char *current_line,
    sfTexture *plane_texture, unsigned int w_width);
tower_t *xyz_file_add_tower_from_line(char *current_line, sfTexture *);

#endif /* !FILE_MANIPULATION_H_ */
