/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort
*/
#include "shell.h"

data_t *last_cell(data_t *first)
{
    data_t *tmp = first;

    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}

static int test_cmp(char *args, char *str)
{
    for (int i = 0; args[i] && str[i]; i++)
        if (args[i] != str[i])
            return 0;
    return 1;
}

static int get_flags(database_t *datab, char **args, int i)
{
    if (test_cmp(args[i], "NAME"))
        sort_name(datab);
    if (test_cmp(args[i], "ID"))
        sort_id(datab);
    if (test_cmp(args[i], "TYPE"))
        sort_type(datab);
    return 0;
}

int sort(void *data, char **args)
{
    database_t *datab = data;

    if (my_arrlen(args) == 0)
        return 84;
    for (int i = 0; args[i]; i++)
        get_flags(datab, args, i);
    return 0;
}
