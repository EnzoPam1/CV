/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>

typedef int (*specifier_function)(va_list *);

typedef struct specifiers_s {
    char specifier;
    specifier_function func;
} specifiers_t;

int my_printf(const char *format, ...);
int handle_specifier(char specifier, va_list *args);
unsigned int my_putnbr_base(unsigned int nbr, char *base);
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
int my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

#endif /* MY_H_ */
