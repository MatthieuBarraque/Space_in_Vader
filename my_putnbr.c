/*
** EPITECH PROJECT, 2022
** my_putnbr.c
** File description:
** my_putnbr.c
*/
#include "my.h"

void my_putnbr(int nb)
{
    int i = 0;
    if (nb <= 9 && nb >= 0)
        my_putchar(nb + '0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (- 1);
        if (nb <= 9 && nb >= 0)
            my_putnbr(nb);
    }
    if (nb > 9) {
        i = nb % 10;
        my_putnbr(nb / 10);
        my_putchar(i + '0');
    }
}
