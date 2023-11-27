/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** del
*/
#include "shell.h"

int del(void *data, char **args)
{
    if (my_arrlen(args) == 0)
        return 84;
    write(1, "DEL", 3);
    return 0;
}
