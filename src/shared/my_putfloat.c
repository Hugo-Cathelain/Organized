/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** my_putfloat
*/

#include "shell.h"

void my_putfloat(double dnbr)
{
    int nbr = dnbr;
    unsigned int devider = 1;

    if (dnbr < 0 && dnbr < (-0.01)) {
        my_putchar('-');
        dnbr = -dnbr;
        nbr = -nbr;
    }
    while (nbr / devider > 9)
        devider *= 10;
    while (devider > 0) {
        my_putnbr((nbr / devider) % 10);
        devider /= 10;
    }
    my_putchar('.');
    nbr = dnbr * 100.0f  + 0.5;
    my_putnbr((nbr / 10) % 10);
    my_putnbr((nbr / 1) % 10);
}
