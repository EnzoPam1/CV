/*
** EPITECH PROJECT, 2023
** template
** File description:
** my_showmem
*/

#include <unistd.h>
#include "../../include/my.h"

static void print_hex_byte(char c)
{
    char hex_chars[] = "0123456789ABCDEF";

    write(1, &hex_chars[c / 16], 1);
    write(1, &hex_chars[c % 16], 1);
}

static void print_memory_line(char const *str, int start, int end)
{
    int i;

    for (i = start; i < end; i++) {
        if (i < my_strlen(str)) {
            print_hex_byte(str[i]);
        } else {
            write(1, "  ", 2);
        }
        if (i % 2 == 1) {
            write(1, " ", 1);
        }
    }
    for (i = start; i < end; i++) {
        if (i < my_strlen(str) && str[i] >= 32 && str[i] <= 126) {
            write(1, &str[i], 1);
        } else {
            write(1, ".", 1);
        }
    }
    write(1, "\n", 1);
}

int my_showmem(char const *str, int size)
{
    int i;

    for (i = 0; i < size; i += 16) {
        print_hex_byte((char)(i >> 8));
        print_hex_byte((char)i);
        write(1, ": ", 2);
        print_memory_line(str, i, i + 16);
    }
    return 0;
}
