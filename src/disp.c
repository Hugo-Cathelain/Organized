/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** disp
*/
#include "shell.h"

int disp(void *data, char **args)
{
    database_t *datab = data;
    data_t *tmp = datab->begin;

    if (my_arrlen(args) != 0)
        return 84;
    while (tmp != NULL) {
        my_putstr(tmp->type);
        my_putstr(" n°");
        my_putnbr(tmp->id);
        my_putstr(" - “");
        my_putstr(tmp->data);
        my_putstr("”\n");
        tmp = tmp->next;
    }
    return 0;
}
