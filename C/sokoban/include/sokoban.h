/*
** EPITECH PROJECT, 2023
** Sokoban Project
** File description:
** Header for Sokoban Game
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>
#include "my.h"

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_
    #define UP 65
    #define DOWN 66
    #define RIGHT 67
    #define LEFT 68
    #define SPACE 32

struct game_state {
    char *data_buffer;
    char **initial_state;
    char **game_map;
    int position_y;
    int saveposition_y;
    int position_x;
    int saveposition_x;
};

typedef struct {
    int *er;
    int *nb;
} BoxParams;

void go_right(struct game_state *game_state_instance);
void go_left(struct game_state *game_state_instance);
void go_up(struct game_state *game_state_instance);
void go_down(struct game_state *game_state_instance);
void moves(struct game_state *game_state_instance, int input);
int check_win(struct game_state *game_state_instance);
int is_block(char **tab, int position_y, int position_x);
int check_loose(char **tab);
void check_game_map(struct game_state *game_state_instance);
int nb_line(char **tab);
void fill_struct(struct game_state *game_state_instance);
void changes(struct game_state *game_state_instance);
void change_carac(struct game_state *game_state_instance,
    int position_y, int position_x);
void start_sokoban(struct game_state *game_state_instance);
void displaycurse(struct game_state *game_state_instance);
char *open_file(char *name);
int check_is_oo(int position_y, int position_x,
    struct game_state *game_state_instance);

#endif /* SOKOBAN_H_ */
