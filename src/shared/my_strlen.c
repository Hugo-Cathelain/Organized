/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int count = 0;

    while (*str != '\0') {
        str++;
        count++;
    }
    return count;
}
