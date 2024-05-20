/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** quadtree
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../../include/building/quadtree.h"
#include "../../../include/utils.h"

quadtree_t *xyz_quadtree_quadtree_create(sfIntRect boundary)
{
    quadtree_t *quadtree = malloc(sizeof(*quadtree));

    if (!quadtree)
        return (NULL);
    quadtree->boundary = boundary;
    quadtree->children = NULL;
    quadtree->is_divided = sfFalse;
    quadtree->nb_planes = 0;
    quadtree->planes = malloc(sizeof(plane_t *) * (QT_CAPACITY + 1));
    if (!(quadtree->planes))
        return (NULL);
    for (unsigned int i = 0; i <= QT_CAPACITY; i++)
        quadtree->planes[i] = NULL;
    return (quadtree);
}

void xyz_quadtree_quadtree_clear(quadtree_t *quadtree)
{
    if (quadtree->is_divided) {
        for (unsigned int i = 0; quadtree->children[i]; i++) {
            xyz_quadtree_quadtree_clear(quadtree->children[i]);
            free(quadtree->children[i]);
        }
        quadtree->is_divided = sfFalse;
    }
    for (unsigned int i = 0; quadtree->planes[i]; i++)
        quadtree->planes[i] = NULL;
    quadtree->nb_planes = 0;
}

static int subdivide_and_reinsert(quadtree_t *quadtree)
{
    if (xyz_quadtree_quadtree_subdivide(&quadtree) != 0)
        return (-1);
    for (unsigned int i = 0; i < QT_CAPACITY; i++) {
        xyz_quadtree_quadtree_insert(quadtree, quadtree->planes[i]);
        quadtree->planes[i] = NULL;
    }
    return 0;
}

static int insert_into_children(quadtree_t *quadtree, plane_t *plane)
{
    for (unsigned int i = 0; i < 4; i++)
        if (xyz_quadtree_quadtree_insert(quadtree->children[i], plane) == 0)
            return 0;
    return 1;
}

int xyz_quadtree_quadtree_insert(quadtree_t *quadtree, plane_t *plane)
{
    if (!(xyz_utils_boundary_contains_pos(quadtree->boundary,
        plane->path->pos)))
        return (1);
    if (quadtree->nb_planes < QT_CAPACITY && !(quadtree->is_divided)) {
        quadtree->planes[quadtree->nb_planes] = plane;
        quadtree->nb_planes++;
        return (0);
    }
    if (!(quadtree->is_divided)) {
        if (subdivide_and_reinsert(quadtree) != 0)
            return (-1);
    }
    if (insert_into_children(quadtree, plane) == 0) {
        quadtree->nb_planes++;
        return (0);
    }
    return (1);
}

static int create_child_quadtree(quadtree_t **child, Rectangle rect)
{
    *child = xyz_quadtree_quadtree_create((sfIntRect) {rect.x, rect.y,
        rect.width, rect.height});
    return (*child == NULL) ? 1 : 0;
}

int xyz_quadtree_quadtree_subdivide(quadtree_t **quadtree)
{
    int x = (*quadtree)->boundary.left;
    int y = (*quadtree)->boundary.top;
    int w = (*quadtree)->boundary.width / 2;
    int h = (*quadtree)->boundary.height / 2;
    Rectangle rect;

    (*quadtree)->children = malloc(sizeof(quadtree_t *) * (4 + 1));
    if (!((*quadtree)->children))
        return (1);
    for (int i = 0; i < 4; i++) {
        rect.x = x + (i % 2) * w;
        rect.y = y + (i / 2) * h;
        rect.width = w;
        rect.height = h;
        if (create_child_quadtree(&(*quadtree)->children[i], rect))
            return (1);
    }
    (*quadtree)->children[4] = NULL;
    (*quadtree)->is_divided = sfTrue;
    return (0);
}
