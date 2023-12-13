/*
** EPITECH PROJECT, 2023
** strisalpha
** File description:
** strisalpha day6
*/

int is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i]){
        if (!is_lowercase(str[i]) && !is_uppercase(str[i]))
            return (0);
        i++;
    }
    return (1);
}
