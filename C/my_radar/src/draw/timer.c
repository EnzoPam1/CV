/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_draw_timer
*/

#include <stdlib.h>
#include "../../include/my.h"
#include "../../include/building/simulation/sim_texts.h"
#include "../../include/utils.h"

static char *get_str_timer(unsigned int c_time)
{
    char *string = malloc(sizeof(char) * 6);
    unsigned int minutes = c_time / 60;
    unsigned int seconds = c_time % 60;

    string[0] = '\0';
    if (minutes < 10)
        string = my_strcat(string, "0");
    string = my_strcat(string, my_int_to_strnum(minutes));
    string = my_strcat(string, ":");
    if (seconds < 10)
        string = my_strcat(string, "0");
    string = my_strcat(string, my_int_to_strnum(seconds));
    return (string);
}

void xyz_draw_timer(sfRenderWindow *window, text_t *timer_text,
    unsigned int c_time)
{
    sfText_setString(timer_text, get_str_timer(c_time));
    sfRenderWindow_drawText(window, timer_text, NULL);
}
