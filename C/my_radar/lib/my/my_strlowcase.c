/*
** EPITECH PROJECT, 2023
** strlowcase
** File description:
** strlowcase day6
*/

char *my_strlowcase(char *str)
{
    char *current = str;

    while (*current){
        if (*current >= 'A' && *current <= 'Z')
            *current = *current + ('a' - 'A');
        current++;
    }
    return (str);
}
