/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** list_functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../include/my.h"

static int reverse_compare(const struct dirent **a, const struct dirent **b)
{
    return strcmp((*b)->d_name, (*a)->d_name);
}

static int time_compare(const struct dirent **a, const struct dirent **b)
{
    struct stat statA;
    struct stat statB;

    stat((*a)->d_name, &statA);
    stat((*b)->d_name, &statB);
    return statB.st_mtime - statA.st_mtime;
}

void list_directory_sort_time(const t_options *options, const char *path)
{
    struct dirent **file_list;
    int count;

    count = scandir(path, &file_list, NULL,
        options->reverse ? reverse_compare : time_compare);
    if (count < 0) {
        perror("scandir");
        return;
    }
    process_file_list(file_list, count, options);
    free_file_list(file_list, count);
}

void process_file_list(struct dirent **file_list, int count,
    const t_options *options)
{
    for (int i = 0; i < count; i++) {
        if (!options->all && file_list[i]->d_name[0] == '.') {
            continue;
        }
        my_putstr(file_list[i]->d_name);
        my_putchar('\n');
    }
}

void free_file_list(struct dirent **file_list, int count)
{
    for (int i = 0; i < count; i++) {
        free(file_list[i]);
    }
    free(file_list);
}
