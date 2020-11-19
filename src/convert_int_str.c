/*
** EPITECH PROJECT, 2018
** convert_int_str
** File description:
** convert int to str
*/

#include "my.h"

int my_intlen(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb *= -1;
        i++;
    }
    for (; nb > 0; i++)
        nb /= 10;
    return (i);
}

char *check_str(char *str, int i)
{
    if (i == 0) {
        str[0] = '0';
        str[1] = 0;
    }
    return (str);
}

char *convert_int_str(int nb)
{
    char *result = malloc(sizeof(char) * my_intlen(nb));
    int i = 0;
    bool neg = false;

    if (nb < 0) {
        nb *= -1;
        neg = true;
    }
    for (; nb > 0; i++) {
        result[i] = nb % 10 + '0';
        nb /= 10;
    }
    if (neg == true) {
        result[i] = '-';
        i++;
    }
    result[i] = 0;
    result = my_revstr(result);
    return (check_str(result, i));
}
