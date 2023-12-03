/*
** EPITECH PROJECT, 2023
** tests
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Teste un string simple
Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

// Teste un nombre simple
Test(my_printf, display_integer, .init = redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

// Teste un charactère simple
Test(my_printf, display_char, .init = redirect_all_std)
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

// Teste un string
Test(my_printf, display_string, .init = redirect_all_std)
{
    char str[] = "Epitech";
    my_printf("%s", str);
    cr_assert_stdout_eq_str("Epitech");
}

// Teste un multiple caractères 
Test(my_printf, multiple_chars, .init = redirect_all_std)
{
    my_printf("Hello %c", 'W');
    cr_assert_stdout_eq_str("Hello W");
}

// Teste un nombre positif 
Test(my_printf, positive_integer, .init = redirect_all_std)
{
    my_printf("%d", 12345);
    cr_assert_stdout_eq_str("12345");
}

// Teste un nombre négatif
Test(my_printf, negative_integer, .init = redirect_all_std)
{
    my_printf("%d", -12345);
    cr_assert_stdout_eq_str("-12345");
}

// Teste un nombre hexadécimal (en minuscules)
Test(my_printf, hex_lower, .init = redirect_all_std)
{
    my_printf("%x", 255);
    cr_assert_stdout_eq_str("ff");
}

// Teste un nombre hexadécimal (en majuscules)
Test(my_printf, hex_upper, .init = redirect_all_std)
{
    my_printf("%X", 255);
    cr_assert_stdout_eq_str("FF");
}

// Teste un nombre en octal
Test(my_printf, octal, .init = redirect_all_std)
{
    my_printf("%o", 9);
    cr_assert_stdout_eq_str("11");
}

// Teste un pourcentage
Test(my_printf, percentage, .init = redirect_all_std)
{
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

// Teste un nombre non signé
Test(my_printf, unsigned_int, .init = redirect_all_std)
{
    my_printf("%u", 12345);
    cr_assert_stdout_eq_str("12345");
}

// Teste une adresse mémoire
Test(my_printf, pointer_address, .init = redirect_all_std)
{
    int x = 42;
    char expected_output[50];
    sprintf(expected_output, "%p", &x);
    my_printf("%p", &x);
    cr_assert_stdout_eq_str(expected_output);
}

// Teste une chaîne avec des espaces
Test(my_printf, string_with_spaces, .init = redirect_all_std)
{
    char str[] = "Hello World!";
    my_printf("%s", str);
    cr_assert_stdout_eq_str("Hello World!");
}

// Teste un entier avec des zéros en tête
Test(my_printf, integer_with_leading_zeros, .init = redirect_all_std)
{
    my_printf("%05d", 42);
    cr_assert_stdout_eq_str("00042");
}

// Teste une largeur minimum pour une chaîne
Test(my_printf, string_min_width, .init = redirect_all_std)
{
    char str[] = "Hello";
    my_printf("%10s", str);
    cr_assert_stdout_eq_str("     Hello");
}

// Teste l'affichage d'un caractère spécial
Test(my_printf, special_character, .init = redirect_all_std)
{
    my_printf("%c", '\n');
    cr_assert_stdout_eq_str("\n");
}

// Teste l'affichage de plusieurs spécificateurs
Test(my_printf, multiple_specifiers, .init = redirect_all_std)
{
    my_printf("This is a number: %d, and this is a char: %c", 1234, 'A');
    cr_assert_stdout_eq_str("This is a number: 1234, and this is a char: A");
}

// Teste un nombre à virgule fixe
Test(my_printf, fixed_point_number, .init = redirect_all_std)
{
    my_printf("%.2f", 123.4567);
    cr_assert_stdout_eq_str("123.46");
}

// Teste un nombre en notation scientifique
Test(my_printf, scientific_notation, .init = redirect_all_std)
{
    my_printf("%.3e", 1234.56);
    cr_assert_stdout_eq_str("1.235e+03");
}

// Teste un nombre avec des groupes de mille
Test(my_printf, thousand_grouping, .init = redirect_all_std)
{
    my_printf("%'d", 1234567);
    cr_assert_stdout_eq_str("1,234,567");
}

Test(my_printf, basic_binary_conversion, .init=redirect_all_std)
{
    my_printf("%b", 5); // 5 en binaire est 101.
    cr_assert_stdout_eq_str("101");
}

Test(my_printf, zero_binary_conversion, .init=redirect_all_std)
{
    my_printf("%b", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, large_number_binary_conversion, .init=redirect_all_std)
{
    my_printf("%b", 255); // 255 en binaire est 11111111.
    cr_assert_stdout_eq_str("11111111");
}