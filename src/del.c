/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** del
*/
#include "shell.h"

static void print_del(data_t *current)
{
    write(1, current->type, my_strlen(current->type));
    my_putstr(" n°");
    my_putnbr(current->id);
    my_putstr(" - \"");
    write(1, current->data, my_strlen(current->data));
    my_putstr("\" deleted.\n");
}

int del_relay(data_t *current, data_t *tmp, database_t *datab, int id)
{
    while (current != NULL && current->id != id) {
        tmp = current;
        current = current->next;
    }
    if (current == NULL)
        return 0;
    print_del(current);
    if (tmp == NULL)
        datab->begin = current->next;
    else
        tmp->next = current->next;
    free(current->data);
    free(current->type);
    free(current->next);
    free(current);
    return 0;
}

int del(void *data, char **args)
{
    database_t *datab = data;
    data_t *current = datab->begin;
    data_t *tmp = NULL;
    int id;

    if (my_arrlen(args) == 0)
        return 84;
    for (int i = 0; args[i]; i++) {
        current = datab->begin;
        id = my_atoi(args[i]);
        del_relay(current, tmp, datab, id);
    }
    return 0;
}
