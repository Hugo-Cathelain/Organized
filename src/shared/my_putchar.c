/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_putchar
*/

#include "shell.h"

void my_putchar(char ch)
{
    write(1, &ch, 1);
}
