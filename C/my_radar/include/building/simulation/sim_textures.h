/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim_textures
*/

#include <SFML/Graphics.h>

#ifndef SIM_TEXTURES_H_
    #define SIM_TEXTURES_H_

    #define SIM_BG_TEXTURE_PATH        "ressources/world.jpg"
    #define PLANE_TEXTURE_PATH         "ressources/plane.png"
    #define TOWER_TEXTURE_PATH         "ressources/tower.png"

typedef sfTexture texture_t;

typedef struct sim_textures {
    texture_t *sim_bg;
    texture_t *plane;
    texture_t *tower;
} sim_textures_t;
typedef sim_textures_t textures_t;

sim_textures_t *xyz_textures_sim_textures_create(void);
void xyz_textures_sim_textures_destroy(sim_textures_t *);

#endif /* !SIM_TEXTURES_H_ */
