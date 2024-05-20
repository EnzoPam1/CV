/*
** EPITECH PROJECT, 2023
** strisprintable
** File description:
** strisprintable day6
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < 32 || str[i] > 126)
            return (0);
        i++;
    }
    return (1);
}
