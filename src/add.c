/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** add
*/
#include "shell.h"

static int test_wire(char *arg)
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

int test_type(char *arg)
{
    if (my_strlen(arg) >= 4)
        return test_wire(arg);
    return 0;
}

int add(void *data, char **args)
{
    data_t *tmp;
    data_t *datas;
    int i = 0;

    tmp = data;
    if (my_arrlen(args) % 2 != 0 || my_arrlen(args) == 0)
        return 84;
    for (i = 0; args[i]; i++) {
        if (test_type(args[i]))
            tmp->type = args[i];
        else
            return 84;
        datas = malloc(sizeof(data_t));
        tmp->data = args[i + 1];
        tmp->next = datas;
        tmp = datas;
        i++;
    }
    write(1, "ADD", 3);
    return 0;
}
