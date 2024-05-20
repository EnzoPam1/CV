/*
** EPITECH PROJECT, 2023
** Sokoban Project
** File description:
** File opening and reading for Sokoban Game
*/

#include "../include/sokoban.h"
#include "../include/my.h"

char *open_file(char *name)
{
    FILE *fd = fopen(name, "r");
    ssize_t read;
    size_t len = 0;
    char *buffer = NULL;
    char *final = strdup("\n");

    if (fd == NULL)
        exit(84);
    while (true) {
        read = getline(&buffer, &len, fd);
        if (read == -1)
            break;
        final = my_strcat(final, buffer);
    }
    fclose(fd);
    free(buffer);
    return final;
}
