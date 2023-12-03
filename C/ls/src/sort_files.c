/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** sort_files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "../include/my.h"

static int compare_mtime(const struct dirent **a, const struct dirent **b)
{
    int reverse_sort = 0;
    struct stat statA;
    struct stat statB;
    int result = (statA.st_mtime > statB.st_mtime) -
        (statB.st_mtime > statA.st_mtime);

    stat((*a)->d_name, &statA);
    stat((*b)->d_name, &statB);
    return reverse_sort ? -result : result;
}

void sort_files_by_time(struct dirent ***file_list, int *count,
    const char *dir_name)
{
    *count = scandir(dir_name, file_list, NULL, alphasort);
    if (*count < 0) {
        perror("scandir");
    } else {
        qsort(*file_list, *count, sizeof(struct dirent *), (int (*)
            (const void *,const void *))compare_mtime);
    }
}
