/*
** EPITECH PROJECT, 2023
** strisnum
** File description:
** strisnum day6
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
