/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** xyz_file_get_file_buffer
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../../include/file_manipulation.h"
#include "../../include/my.h"

char *xyz_file_get_file_buffer(char const *filepath)
{
    int fd = 0;
    unsigned int file_size = xyz_file_get_file_size(filepath);
    char *buffer = malloc(sizeof(char) * (file_size + 1));

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_puterr(OPEN_FAILURE_MSG);
        return (NULL);
    }
    if (read(fd, buffer, file_size) == -1) {
        my_puterr(READ_FAILURE_MSG);
        return (NULL);
    }
    buffer[file_size] = '\0';
    close(fd);
    return (buffer);
}

unsigned int xyz_file_get_file_size(char const *filepath)
{
    struct stat stats;

    if (stat(filepath, &stats) != 0)
        return (-1);
    return (stats.st_size);
}
