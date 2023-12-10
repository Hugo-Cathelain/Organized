/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort_id
*/
#include "shell.h"

data_t *last_cell(data_t *first)
{
    data_t *tmp = first;

    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}

data_t *partition(data_t *first, data_t *last)
{
    data_t *pivot = first;
    data_t *front = first;
    int temp = 0;

    while (front != NULL && front != last) {
        if (front->id < last->id) {
            pivot = first;
            temp = first->id;
            first->id = front->id;
            front->id = temp;
            first = first->next;
        }
        front = front->next;
    }
    temp = first->id;
    first->id = last->id;
    last->id = temp;
    return pivot;
}

void quick_sort(data_t *first, data_t *last)
{
    data_t *pivot;

    if (first == last) {
        return;
    }
    pivot = partition(first, last);
    if (pivot != NULL && pivot->next != NULL) {
        quick_sort(pivot->next, last);
    }
    if (pivot != NULL && first != pivot) {
        quick_sort(first, pivot);
    }
}

void sort_id(database_t *datab)
{
    data_t *current = datab->begin;

    quick_sort(current, last_cell(current));
}
