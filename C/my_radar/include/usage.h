/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** usage
*/

#ifndef USAGE_H_
    #define USAGE_H_

    #define MY_EXIT_SUCCESS         0
    #define MY_EXIT_OPTION          192
    #define MY_EXIT_FAILURE         84

    #define SHORT_DESC "Air traffic simulation panel"
    #define USAGE_1 "USAGE: ./my_radar [OPTIONS] path_to_script"
    #define USAGE_2 "path_to_script: Path of the script file."
    #define OPTIONS_1 "-h | --help: Print usage and quit."
    #define USER_INT_1 "'L' key: Toggle hitboxes/areas."
    #define USER_INT_2 "'S' key: Toggle sprites."

int xyz_usage_check_args(int ac, char **av);
int xyz_usage_check_options(char *arg);
void xyz_usage_print_help(void);
void xyz_usage_print_bad_ac(int ac, char **av);

#endif /* !USAGE_H_ */
