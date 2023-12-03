/*
** EPITECH PROJECT, 2023
** B-PSU-100-NCY-1-1-myls-enzo.pambout
** File description:
** parse_args
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my.h"

t_options default_options(void)
{
    t_options opts = {0};

    opts.list_long = false;
    opts.recursive = false;
    opts.sort_time = false;
    opts.reverse = false;
    opts.all = false;
    opts.error_flag = false;
    opts.directory_only = false;
    return opts;
}

parsed_args parse_arguments(int argc, char **argv)
{
    parsed_args result;
    
    result.opts = default_options();
    result.files = malloc(sizeof(char*) * argc);
    result.file_count = 0;
    int arg_index = 1;

    while (arg_index < argc) {
        const char *arg = argv[arg_index];

        if (arg[0] == '-') {
            for (int i = 1; arg[i] != '\0'; i++) {
                char opt = arg[i];
                if (opt == 'l') {
                    result.opts.list_long = true;
                } else if (opt == 'R') {
                    result.opts.recursive = true;
                } else if (opt == 't') {
                    result.opts.sort_time = true;
                } else if (opt == 'r') {
                    result.opts.reverse = true;
                } else if (opt == 'a') {
                    result.opts.all = true;
                } else if (opt == 'd') {
                    result.opts.directory_only = true;
                } else {
                    my_putstr("Invalid option: "); 
                    my_putchar(opt); 
                    my_putchar('\n');
                    result.opts.error_flag = true;
                    return result;
                }
            }
        } else {
            result.files[result.file_count++] = argv[arg_index];
        }
        arg_index++;
    }
    return result;
}
