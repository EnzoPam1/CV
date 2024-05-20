/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** my_navy
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <signal.h>
#include "my.h"

#ifndef MY_NAVY_H_
    #define MY_NAVY_H_

#ifndef READ_SIZE
    #define READ_SIZE (4096)
#endif

    #define GRID_HEIGHT 8
    #define GRID_WIDTH 8
    #define SHIP_CELL 's'
    #define HIT_CELL 'x'
    #define EXPECTED_SHIP_CELLS 14
    #define EMPTY_CELL '.'
    #define MISS_CELL 'o'

typedef struct {
    char **player_map;
    char **opponent_map;
    char *current_target;
    int player_id;
    int opponent_id;
    int is_game_finished;
} game_status_t;

typedef struct {
    int parent_pid;
    int signal_state;
    int signal_flag;
    char *signal_str;
    int counter;
    int feedback;
} global_signals_t;

typedef struct {
    char *str;
    int start;
    int end;
    int step;
} check_params_t;

typedef struct {
    int index;
    int *x;
    int *y;
} position_info_t;

int validate_player_file(char *str);
int validate_game_map(char *str);
void display_help_message(void);
void display_game_map(char **map);
int check_for_collisions(char **map);
void display_full_game_status(game_status_t *status);
int check_win_condition(char **map);
int perform_check(char *str);
char *concatenate_strings(char *result, char *buffer, int size);
char *extract_remaining_string(char *str);
char *read_next_line(int fd);
void process_signal(int signal, siginfo_t *si, void *context);
void handle_signal_response(int signal, siginfo_t *si, void *context);
void setup_signal_reception(void);
int await_response(void);
int receive_signal(void);
char **position_boats(char **map, char *buffer);
char **prepare_game_map(char *file);
int setup_game_structure(game_status_t *status, char **av, int ac);
int check_file_existence(char *file);
void initiate_game(void);
void initiate_alternate_game(void);
int start_player_one_game(game_status_t *one);
int start_player_two_game(game_status_t *two, char **av);
int send_signal_data(int nb1, int nb2, int pid);
char *determine_hit_or_miss(game_status_t *status, char *s);
char *verify_and_send(game_status_t *one);
int initialize_global_state(void);
void reset_global_state(void);

#endif /* !MY_NAVY_H_ */
