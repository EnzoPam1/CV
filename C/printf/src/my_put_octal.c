/*
** EPITECH PROJECT, 2023
** my_put_octal
** File description:
** my_put_octal
*/

int my_put_octal(unsigned int n)
{
    int count = 0;

    if (n >= 8) {
        count += my_put_octal(n / 8);
    }
    count += my_putchar(n % 8 + '0');
    return count;
}
