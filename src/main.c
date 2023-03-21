/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    var->room_nb = 0;

    if (argc != 1)
        return 84;
    read_file(var);
    return 0;
}
