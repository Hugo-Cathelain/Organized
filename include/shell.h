/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** shell.h
*/

#ifndef SHELL_H
    #define SHELL_H

    #include <unistd.h>
    #include <stdlib.h>

typedef struct datastructure {
    char *data;
    char *type;
    int id;
    struct datas *next;
} data_t;

typedef struct database {
    data_t *begin;
    int curent_id;
} database_t;

int my_strlen(char *str);
int my_arrlen(char **arr);
void my_putstr(char *str);
void my_putfloat(double dnbr);
void my_putchar(char ch);
void my_putnbr(int number);
int my_atoi(char *nptr);
int my_isdigit(char ch);
double my_atof(const char *str);

// To be implemented
int add(void *data, char **args);
int del(void *data, char **args);
int sort(void *data, char **args);
int disp(void *data, char **args);

// Already implemented
int workshop_shell(void *data);

#endif /* SHELL_H */
