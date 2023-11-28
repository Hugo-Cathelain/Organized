/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** add
*/
#include "shell.h"

int test_type(char *arg)
{
    if (my_strlen(arg) == 4 && arg[0] == 'W' && arg[1] == 'I' &&
        arg[2] == 'R' && arg[3] == 'E')
        return 1;
    if (my_strlen(arg) == 6 && arg[0] == 'S' && arg[1] == 'E' &&
        arg[2] == 'N' && arg[3] == 'S' && arg[4] == 'O' && arg[5] == 'R')
        return 1;
    if (my_strlen(arg) == 6 && arg[0] == 'D' && arg[1] == 'E' &&
        arg[2] == 'V' && arg[3] == 'I' && arg[4] == 'C' && arg[5] == 'E')
        return 1;
    if (my_strlen(arg) == 8 && arg[0] == 'A' && arg[1] == 'C' &&
        arg[2] == 'T' && arg[3] == 'U' && arg[4] == 'A' &&
        arg[5] == 'T' && arg[6] == 'O' && arg[7] == 'R')
        return 1;
    if (my_strlen(arg) == 9 && arg[0] == 'P' && arg[1] == 'R' &&
        arg[2] == 'O' && arg[3] == 'C' && arg[4] == 'E' &&
        arg[5] == 'S' && arg[6] == 'S' && arg[7] == 'O' && arg[8] == 'R')
        return 1;
    return 0;
}

static void print_added(data_t *tmp)
{
    write(1, tmp->type, my_strlen(tmp->type));
    my_putstr(" n°");
    my_putnbr(tmp->id);
    my_putstr(" - “");
    write(1, tmp->data, my_strlen(tmp->data));
    my_putstr("” added.\n");
}

static char *get_arg(char *args)
{
    char *str = malloc(sizeof(char) * my_strlen(args) + 1);
    int i = 0;

    for (i = 0; args[i]; i++)
        str[i] = args[i];
    str[i] = '\0';
    return str;
}

data_t *add_relay(data_t *tmp, database_t *datab, char *arg)
{
    tmp->data = malloc(my_strlen(arg) + 1);
    tmp->data = get_arg(arg);
    tmp->id = datab->curent_id;
    datab->curent_id++;
    print_added(tmp);
    tmp->next = datab->begin;
    datab->begin = tmp;
    return tmp;
}

int add(void *data, char **args)
{
    database_t *datab = data;
    data_t *tmp;
    int i = 0;

    if (my_arrlen(args) % 2 != 0 || my_arrlen(args) == 0)
        return 84;
    for (i = 0; args[i]; i++) {
        tmp = malloc(sizeof(data_t));
        tmp->type = malloc(my_strlen(args[i]) + 1);
        if (test_type(args[i]))
            tmp->type = get_arg(args[i]);
        else
            return 84;
        tmp = add_relay(tmp, datab, args[i + 1]);
        i++;
    }
    return 0;
}
