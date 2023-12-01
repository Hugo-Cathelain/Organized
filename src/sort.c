/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** sort
*/
#include "shell.h"

static int test_type(char *args)
{
    char str[4] = "TYPE";

    for (int i = 0; args[i]; i++)
        if (args[i] != str[i])
            return 0;
    return 1;
}

static int test_id(char *args)
{
    char str[2] = "ID";

    for (int i = 0; args[i]; i++)
        if (args[i] != str[i])
            return 0;
    return 1;
}

static int test_name(char *args)
{
    char str[4] = "NAME";

    for (int i = 0; args[i]; i++)
        if (args[i] != str[i])
            return 0;
    return 1;
}

static int get_flags(database_t *datab, char **args, int i)
{
    if (test_name(args[i])) {
        sort_name(datab);
        sort_name(datab);
    }
    if (test_id(args[i])) {
        sort_id(datab);
        sort_id(datab);
    }
    if (test_type(args[i])) {
        sort_type(datab);
        sort_type(datab);
    }
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
