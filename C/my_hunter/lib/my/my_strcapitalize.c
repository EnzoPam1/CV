/*
** EPITECH PROJECT, 2023
** strcapitalize
** File description:
** strcapitalize day6
*/

static int is_alpha_numeric(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    char    *current = str;
    int     capitalize_next = 1;

    while (*current){
        if (*current >= 'A' && *current <= 'Z')
            *current = *current + ('a' - 'A');
        if (capitalize_next && *current >= 'a' && *current <= 'z'){
            *current = *current - ('a' - 'A');
            capitalize_next = 0;
        }
        if (!is_alpha_numeric(*current))
            capitalize_next = 1;
        else
            capitalize_next = 0;
        current++;
    }
    return (str);
}
