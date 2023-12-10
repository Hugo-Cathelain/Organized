/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort_id
*/
#include "shell.h"

void sort_id_relay(data_t *prev, data_t *current, data_t *next,
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

void sort_id(database_t *datab)
{
    data_t *current = datab->begin;
    data_t *prev = NULL;
    data_t *next = current->next;

    if (next == NULL || current == NULL)
        return;
    while (next != NULL) {
        if (current->id > next->id) {
            sort_id_relay(prev, current, next, datab);
            current = datab->begin;
            next = current->next;
        }
        prev = current;
        current = current->next;
        next = current->next;
    }
}
