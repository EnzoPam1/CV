/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** path
*/

#include <SFML/Graphics.h>
#include "tower.h"
#include "utils.h"

#ifndef PATH_H_
    #define PATH_H_

typedef struct path {
    sfVector2f pos;
    sfVector2f end;
    sfVector2f step;
} path_t;

path_t *xyz_path_path_create(sfVector2f beg, sfVector2f end,
    uint speed, uint w_width);
sfVector2f xyz_path_get_step_offset(sfVector2f point_a, sfVector2f point_b);
path_t *xyz_path_get_random_path(tower_t **towers, uint w_width);

#endif /* !PATH_H_ */
