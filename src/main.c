/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** main
*/
#include "shell.h"

int main(int ac, char **av)
{
    database_t *datab = malloc(sizeof(database_t));

    if (ac > 1)
        return 84;
    datab->begin = NULL;
    datab->curent_id = 0;
    return workshop_shell(datab);
}
