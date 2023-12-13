/*
** EPITECH PROJECT, 2023
** strupcase
** File description:
** strupcase day6
*/

char *my_strupcase(char *str)
{
    char *current = str;

    while (*current){
        if (*current >= 'a' && *current <= 'z')
            *current = *current - ('a' - 'A');
        current++;
    }
    return (str);
}
