/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim_fonts
*/

#ifndef SIM_FONTS_H_
    #define SIM_FONTS_H_

    #define SKYFONT_FONT_PATH       "ressources/1.ttf"
    #define FALLING_SKY_FONT_PATH   "ressources/1.ttf"

typedef sfFont font_t;

typedef struct sim_fonts {
    font_t *skyfont;
    font_t *falling_sky;
} sim_fonts_t;
typedef sim_fonts_t fonts_t;

sim_fonts_t *xyz_fonts_sim_fonts_create(void);
void xyz_fonts_sim_fonts_destroy(sim_fonts_t *);

#endif /* !SIM_FONTS_H_ */
