/*
** EPITECH PROJECT, 2023
** strislower
** File description:
** strislower day6
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
        i++;
    }
    return (1);
}
