/*
** EPITECH PROJECT, 2023
** my_str_isnum.c
** File description:
** Returns 1 if the string passed as parameter
** only contains digits and 0 otherwise.
*/

#include <stddef.h>

int my_str_isnum(char const *str)
{
    for (size_t i = 0; str[i] && str[i] != '#'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n' && str[i] != ' ')
            return 0;
    }
    return 1;
}
