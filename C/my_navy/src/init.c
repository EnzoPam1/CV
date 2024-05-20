/*
** EPITECH PROJECT, 2024
** B-PSU-100-NCY-1-1-navy-enzo.pambout
** File description:
** init.c
*/

#include "my_navy.h"

extern global_signals_t *global_signals;

static void update_map_position(char **map, char *buffer,
    position_info_t *pos_info)
{
    while (*(pos_info->y) <= buffer[pos_info->index + 5] - 65 &&
            *(pos_info->x) <= buffer[pos_info->index + 6] - 49) {
        map[*(pos_info->x)][*(pos_info->y)] = buffer[pos_info->index];
        if (buffer[pos_info->index + 2] < buffer[pos_info->index + 5]) {
            (*(pos_info->y))++;
        } else {
            (*(pos_info->x))++;
        }
    }
}

char **position_boats(char **map, char *buffer)
{
    int a = 0;
    int x1;
    int y1;
    position_info_t pos_info;

    while (a <= 26) {
        y1 = buffer[a + 2] - 65;
        x1 = buffer[a + 3] - 49;
        map[x1][y1] = buffer[a];
        pos_info.index = a;
        pos_info.x = &x1;
        pos_info.y = &y1;
        update_map_position(map, buffer, &pos_info);
        a += 8;
    }
    return map;
}

char **create_empty_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    map[8] = NULL;
    for (int i = 0; i <= 7; i++) {
        map[i] = my_strdup("........");
    }
    return map;
}

char **prepare_game_map(char *file)
{
    char **map;
    char *buffer;
    int fd;

    fd = check_file_existence(file);
    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * 33);
    read(fd, buffer, 32);
    buffer[32] = '\0';
    if (validate_game_map(buffer) != 0) {
        free(buffer);
        return NULL;
    }
    map = create_empty_map();
    map = position_boats(map, buffer);
    free(buffer);
    return map;
}

void initialize_status(game_status_t *status)
{
    status->current_target = 0;
    status->player_id = getpid();
    status->is_game_finished = 0;
    status->opponent_id = 0;
}

int setup_game_structure(game_status_t *status, char **av, int ac)
{
    char *file;

    file = (ac == 3) ? av[2] : av[1];
    status->player_map = prepare_game_map(file);
    if (status->player_map == NULL)
        return 84;
    status->opponent_map = create_empty_map();
    initialize_status(status);
    return check_for_collisions(status->player_map);
}
