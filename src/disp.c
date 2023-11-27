/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** disp
*/
#include "shell.h"

int disp(void *data, char **args)
{
    if (my_arrlen(args) != 0)
        return 84;
    write(1, "DISP", 3);
    return 0;
}
