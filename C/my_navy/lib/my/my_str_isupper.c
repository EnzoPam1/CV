/*
** EPITECH PROJECT, 2023
** strisupper
** File description:
** strisupper day6
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i]){
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
        i++;
    }
    return (1);
}
