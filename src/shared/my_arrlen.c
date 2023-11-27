/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-organized-hugo.cathelain
** File description:
** my_arrlen
*/

int my_arrlen(char **arr)
{
    int i = 0;

    while (arr[i])
        i++;
    return i;
}
