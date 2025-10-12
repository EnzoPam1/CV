/*
** EPITECH PROJECT, 2023
** templatemain
** File description:
** templatemain
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "../include/my.h"

int reverse_compare(const struct dirent **a, const struct dirent **b)
{
    return strcmp((*b)->d_name, (*a)->d_name);
}

void sort_and_display(struct dirent **file_list, int count,
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

void list_directory(const t_options *options, const char *path)
{
    struct dirent **file_list;
    int count;

    count = scandir(path, &file_list, NULL,
        options->reverse ? reverse_compare : alphasort);
    if (count < 0) {
        perror("scandir");
    } else {
        sort_and_display(file_list, count, options);
        while (count > 0) {
            count--;
            free(file_list[count]);
        }
        free(file_list);
    }
}

static void execute_ls(const t_options *options, const char *path)
{
    if (options->directory_only) {
        my_putstr(path);
        my_putchar('\n');
    } else if (options->recursive) {
        list_directory_recursive(path, options);
    } else {
        execute_ls_options(options, path);
    }
}

int main(int argc, char **argv)
{
    parsed_args args = parse_arguments(argc, argv);

    if (args.opts.error_flag) {
        my_putstr_err("Erreur: argument invalide.\n");
        free(args.files);
        return 84;
    }
    if (args.file_count == 0) {
        execute_ls(&args.opts, ".");
    } else {
        for (int i = 0; i < args.file_count; i++) {
            execute_ls(&args.opts, args.files[i]);
        }
    }
    free(args.files);
    return 0;
}

