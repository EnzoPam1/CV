/*
** EPITECH PROJECT, 2023
** Day09
** File description:
** task02
*/

#include <stdarg.h>
#include <stdio.h>

#ifndef MY_H
    #define MY_H

typedef int (*specifier_function)(va_list *);

typedef struct specifiers_s {
    char specifier;
    specifier_function func;
} specifiers_t;

typedef struct s_word_params {
    char **words;
    const char *str;
    int start;
    int index;
} t_word_params;

int my_compute_power_it(int, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int);
int my_isalnum(int);
int my_isalpha(int);
int my_isneg(int);
int my_isnum(int);
int my_isprint(int);
int my_isupper(int);
int my_put_nbr(int);
int my_putchar(char c);
int my_putnbr_base(unsigned int nbr, char const *base);
int my_putstr(char const *str);
char *my_revstr(char);
int my_showstr(char const *str);
void my_sort_int_array(int, int);
char *my_strcapitalize(char);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const);
int my_str_islower(char const);
int my_str_isnum(char const);
int my_str_isprintable(char const);
int my_str_isupper(char const);
int my_strlen(char const *);
char *my_strlowcase(char);
char *my_strncat(char, char const, int);
int my_strncmp(char const, char const, int);
char *my_strncpy(char, char const, int);
char *my_strstr(char, char const);
char *my_strupcase(char);
void my_swap(int, int);
int my_showmem(char const *str, int size);
int my_getnbr_base(char const *str, char const *base);
int my_index_of(char const *str, char c);
char **my_str_to_word_array(char const *str);
int fill_words_array(char **words, const char *str);
char *duplicate_word(const char *str, int start, int end);
int is_word_char(char c);
int my_printf(const char *format, ...);
int handle_specifier(char specifier, va_list *args);
unsigned int my_putnbr_base_ulong(unsigned long int nbr, char *base);
int print_char_arg(va_list *args);
int print_string_arg(va_list *args);
int print_int_arg(va_list *args);
int print_octal_arg(va_list *args);
int print_unsigned_arg(va_list *args);
int print_hex_lowercase_arg(va_list *args);
int print_hex_uppercase_arg(va_list *args);
int print_pointer_arg(va_list *args);
int print_percent_sign(va_list *args);
int print_binary_arg(va_list *args);
void int_to_str(int num, char *str);

#endif /* MY_H */
