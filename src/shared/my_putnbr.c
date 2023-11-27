/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** my_putnbr
*/

#include "shell.h"

void my_putnbr(int number)
{
    if (number / 10)
        my_putnbr(number / 10);
    my_putchar(number % 10 + '0');
}
