/*
** EPITECH PROJECT, 2023
** strncmp
** File description:
** strncmp day6
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (n && *s1 && *s2 && *s1 == *s2){
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return (0);
    return (*s1 - *s2);
}
