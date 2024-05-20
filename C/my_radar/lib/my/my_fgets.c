/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCY-1-1-organized-enzo.pambout
** File description:
** my_fgets
*/

#include <stdio.h>
#include <unistd.h>

static int lire_caractere(int fd, char *ch)
{
    return read(fd, ch, 1);
}

static char *finaliser_chaine(char *str, int longueur)
{
    str[longueur] = '\0';
    return str;
}

static int lire_et_verifier(int fd, char *ch, int *i)
{
    int read_bytes = lire_caractere(fd, ch);

    if (read_bytes != 1) {
        return read_bytes;
    }
    (*i)++;
    return 1;
}

char *my_fgets(char *str, int num, int fd)
{
    int i = 0, result;
    char ch;

    while (i < num - 1) {
        result = lire_et_verifier(fd, &ch, &i);
        if (result != 1) {
            break;
        }
        str[i - 1] = ch;
        if (ch == '\n') {
            break;
        }
    }
    if (i == 0 || result == -1) {
        return NULL;
    }
    return finaliser_chaine(str, i);
}
