/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** sim_texts
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../../include/building/simulation/sim_texts.h"
#include "../../../include/building/simulation/sim_fonts.h"
#include "../../../include/building/window.h"

static text_t *init_timer_text(font_t *font, window_t *window)
{
    sfText *timer_text = sfText_create();
    sfVector2f pos = {window->width - 250, 0};

    sfText_setCharacterSize(timer_text, 100);
    sfText_setFont(timer_text, font);
    sfText_setColor(timer_text, sfBlack);
    sfText_setPosition(timer_text, pos);
    return (timer_text);
}

sim_texts_t *xyz_texts_sim_texts_create(sim_fonts_t *fonts, window_t *window)
{
    sim_texts_t *texts = malloc(sizeof(sim_texts_t));

    if (!texts)
        return (NULL);
    texts->timer = init_timer_text(fonts->skyfont, window);
    if (!(texts->timer))
        return (NULL);
    return (texts);
}

void xyz_texts_sim_texts_destroy(sim_texts_t *texts)
{
    if (texts->timer)
        sfText_destroy(texts->timer);
    if (texts)
        free(texts);
}
