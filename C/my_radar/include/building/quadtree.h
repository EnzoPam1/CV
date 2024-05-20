/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** quadtree
*/

#include <SFML/Graphics.h>
#include "plane.h"

#ifndef QUADTREE_H_
    #define QUADTREE_H_

    #define QT_CAPACITY      4

typedef struct quadtree {
    sfIntRect boundary;
    plane_t **planes;
    unsigned int nb_planes;
    struct quadtree **children;
    sfBool is_divided;
} quadtree_t;

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Rectangle;

quadtree_t *xyz_quadtree_quadtree_create(sfIntRect boundary);
void xyz_quadtree_quadtree_clear(quadtree_t *quadtree);
int xyz_quadtree_quadtree_insert(quadtree_t *quadtree, plane_t *plane);
plane_t **xyz_quadtree_quadtree_query(quadtree_t *quadtree,
    sfIntRect const area);
unsigned int xyz_quadtree_quadtree_get_nb_planes_in_area(quadtree_t *quadtree,
    sfIntRect const area);
int xyz_quadtree_quadtree_subdivide(quadtree_t **quadtree);

#endif /* !QUADTREE_H_ */
