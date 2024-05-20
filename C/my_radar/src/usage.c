/*
** EPITECH PROJECT, 2024
** B-MUL-100-NCY-1-1-myradar-enzo.pambout
** File description:
** usage
*/

#include "../include/usage.h"
#include "../include/my.h"

int xyz_usage_check_args(int ac, char **av)
{
    if (ac != 2) {
        xyz_usage_print_bad_ac(ac, av);
        return (MY_EXIT_FAILURE);
    }
    if (xyz_usage_check_options(av[1]) == MY_EXIT_SUCCESS)
        return (MY_EXIT_OPTION);
    return (MY_EXIT_SUCCESS);
}

int xyz_usage_check_options(char *arg)
{
    if (my_strcmp(arg, "-h") == 0 || my_strcmp(arg, "--help") == 0) {
        xyz_usage_print_help();
        return (MY_EXIT_SUCCESS);
    }
    return (MY_EXIT_FAILURE);
}

void xyz_usage_print_help(void)
{
    my_putstr(SHORT_DESC);
    my_putchar('\n');
    my_putchar('\n');
    my_putstr(USAGE_1);
    my_putchar('\n');
    my_putstr(USAGE_2);
    my_putchar('\n');
    my_putchar('\n');
    my_putstr(OPTIONS_1);
    my_putchar('\n');
    my_putstr(USER_INT_1);
    my_putchar('\n');
    my_putstr(USER_INT_2);
    my_putchar('\n');
}

void xyz_usage_print_bad_ac(int ac, char **av)
{
    my_puterr(av[0]);
    my_puterr(": bad arguments: ");
    my_puterr(my_int_to_strnum(ac - 1));
    my_puterr(" given but 1 is required\n");
    my_puterr("retry with -h\n");
}
