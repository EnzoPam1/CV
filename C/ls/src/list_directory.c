/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** list_directory
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

static int reverse_compare(const struct dirent **a, const struct dirent **b)
{
    return strcmp((*b)->d_name, (*a)->d_name);
}

void list_directory_long(const t_options *options, const char *path)
{
    struct dirent **file_list;
    int count = 0;
    long total_blocks = 0;

    count = scandir(path, &file_list, NULL, options->reverse ? reverse_compare : alphasort);

    if (count < 0) {
        perror("scandir");
    } else {
        for (int i = 0; i < count; i++) {
            struct stat file_stat;
            if (stat(file_list[i]->d_name, &file_stat) != -1) {
                if (!options->all && file_list[i]->d_name[0] == '.') {
                    continue;
                }
                total_blocks += file_stat.st_blocks;
            }
        }
        my_putstr("total "); 
        print_long_with_padding(total_blocks / 2, 0);
        my_putchar('\n');

        for (int i = 0; i < count; i++) {
            if (!options->all && file_list[i]->d_name[0] == '.') {
                continue;
            }
            print_file_details(file_list[i]->d_name);
            free(file_list[i]);
        }
        free(file_list);
    }
}

void list_directory_recursive(const char *dir_name, const t_options *options)
{
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    my_putstr(dir_name); 
    my_putstr(":\n");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!options->all && entry->d_name[0] == '.') {
            continue;
        }
        char path[1024];
        my_strcat_with_slash(path, dir_name, entry->d_name);        if (options->list_long) {
            print_file_details(path);
        } else {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }

        struct stat path_stat;
        stat(path, &path_stat);
        if (S_ISDIR(path_stat.st_mode) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            list_directory_recursive(path, options);
        }
    }
    closedir(dir);
}
