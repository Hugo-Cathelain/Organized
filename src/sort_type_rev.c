/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort_type
*/
#include "shell.h"

static data_t *partition(data_t *first, data_t *last)
{
    data_t *pivot = first;
    data_t *front = first;
    data_t *tmp = malloc(sizeof(data_t));

    while (front != NULL && front != last) {
        if (my_strcmp(first->type, last->type) >= 0) {
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

void sort_type_rev(database_t *datab, int i)
{
    data_t *current = datab->begin;
    data_t *tmp = current;
    data_t *tmpp = tmp;

    if (i == 1 && current != NULL)
        quick_sort(current, last_cell(current));
    while (tmp != NULL && i == 1) {
        if (tmp->next != NULL && my_strcmp(tmp->type, tmp->next->type) >= 0)
            quick_sort(current, last_cell(current));
        tmp = tmp->next;
    }
    while (tmp != NULL && i == 2) {
        if (tmp->next != NULL && my_strcmp(tmp->data, tmp->next->data) == 0 &&
            my_strcmp(tmp->type, tmp->next->type) <= 0) {
            quick_sort(tmp, tmp->next);
            tmp = tmpp;
            tmpp = tmpp->next;
        }
        tmp = tmp->next;
    }
}
