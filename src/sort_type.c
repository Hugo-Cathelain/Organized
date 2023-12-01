/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort_type
*/
#include "shell.h"

void sort_type_relay(data_t *prev, data_t *current, data_t *next,
    database_t *datab)
{
    if (prev != NULL) {
        prev->next = next;
        current->next = next->next;
        next->next = current;
    } else {
        datab->begin = next;
        current->next = next->next;
        next->next = current;
    }
}

void sort_type(database_t *datab)
{
    data_t *current = datab->begin;
    data_t *prev = malloc(sizeof(data_t));
    data_t *next = malloc(sizeof(data_t));

    prev = NULL;
    if (next == NULL || current == NULL)
        return;
    next = current->next;
    while (next != NULL) {
        if (my_strcmp(current->type, next->type) > 0) {
            sort_type_relay(prev , current, next, datab);
            current = datab->begin;
            next = current->next;
        }
        prev = current;
        current = current->next;
        next = current->next;
    }
}
