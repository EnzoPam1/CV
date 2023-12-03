/*
** EPITECH PROJECT, 2023
** my_put_hex
** File description:
** my_put_hex
*/

int my_put_hex(unsigned int n, int uppercase)
{
    int count = 0;
    char *hex;

    hex = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16) {
        count += my_put_hex(n / 16, uppercase);
    }
    count += my_putchar(hex[n % 16]);
    return count;
}
