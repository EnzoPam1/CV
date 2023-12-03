/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** execute_ls_options
*/

#include "../include/my.h"

void execute_ls_options(const t_options *options, const char *path)
{
    if (options->list_long) {
        list_directory_long(options, path);
    } else if (options->sort_time) {
        list_directory_sort_time(options, path);
    } else {
        list_directory(options, path);
    }
}
