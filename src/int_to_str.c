/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"


char *int_to_str(int nb)
{
    int len = 1;
    int tmp = nb / 10;
    char *str = NULL;

    if (nb < 0)
        return NULL;
    while (tmp > 0) {
        len++;
        tmp /= 10;
    }
    str = malloc(sizeof(char) * (size_t)(len + 1));
    str[len] = '\0';
    for (int i = len - 1; i >= 0; i--) {
        str[i] = (char)('0' + (nb % 10));
        nb /= 10;
    }
    return str;
}
