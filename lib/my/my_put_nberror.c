/*
** EPITECH PROJECT, 2019
** my_put_nberror
** File description:
** my_put_nberror
*/

#include <unistd.h>

void my_putchar3(char c)
{
    write(2, &c, 1);
}

int my_put_nberror(int nb)
{
    int i = 0;
    unsigned long j = 10;
    unsigned int nb2 = 0;

    if (nb < 0) {
        my_putchar3('-');
        nb = nb * (-1);
    }
    nb2 = nb;
    for (unsigned int copy = nb2; copy / 10 > 0; copy = copy / 10) {
        i++;
        j = j * 10;
    }
    while (i >= 0) {
        my_putchar3((nb2 % j) / (j / 10) + '0');
        j = j / 10;
        i--;
    }
    return (0);
}
