/*
** EPITECH PROJECT, 2023
** B-MUL-100-NCY-1-1-myhunter-enzo.pambout
** File description:
** int_to_str
*/

static int calculate_length(int num)
{
    int len = 0;

    while (num != 0) {
        len++;
        num /= 10;
    }
    return len;
}

void int_to_str(int num, char *str)
{
    int i = 0;
    int rem;
    int len;
    int n;

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    n = num;
    len = calculate_length(n);
    for (i = 0; i < len; i++) {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
