/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort_id
*/
#include "shell.h"

void inverse(data_t *first, data_t *front)
{
    first->id = front->id;
    first->data = my_strdup(front->data);
    first->type = my_strdup(front->type);
}

static data_t *partition(data_t *first, data_t *last)
{
    data_t *pivot = first;
    data_t *front = first;
    data_t *tmp = malloc(sizeof(data_t));

    while (front != NULL && front != last) {
        if (front->id < last->id) {
            pivot = first;
            inverse(tmp, first);
            inverse(first, front);
            inverse(front, tmp);
            first = first->next;
        }
        front = front->next;
    }
    inverse(tmp, first);
    inverse(first, last);
    inverse(last, tmp);
    free(tmp);
    return pivot;
}

static void quick_sort(data_t *first, data_t *last)
{
    data_t *pivot;

    if (first == last)
        return;
    pivot = partition(first, last);
    if (pivot != NULL && pivot->next != NULL)
        quick_sort(pivot->next, last);
    if (pivot != NULL && first != pivot)
        quick_sort(first, pivot);
}

void sort_id(database_t *datab)
{
    data_t *current = datab->begin;

    quick_sort(current, last_cell(current));
}
