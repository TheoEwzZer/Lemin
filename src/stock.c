/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

void stock_start(var_t *var)
{
    char *line = NULL;
    size_t size = 0;

    write(1, "#start\n", 7);
    getline(&line, &size, stdin);
    my_putstr(line);
    create_rooms(var, my_getnbr(line));
    var->graph = var->room[var->room_nb - 1];
}

void stock_end(var_t *var)
{
    char *line = NULL;
    size_t size = 0;

    write(1, "#end\n", 5);
    getline(&line, &size, stdin);
    my_putstr(line);
    create_rooms(var, my_getnbr(line));
    var->end = var->room[var->room_nb - 1];
    var->end_data = my_getnbr(line);
}

bool check_stock(var_t *var, char *line)
{
    if (!my_strcmp(line, "##start\n")) {
        stock_start(var);
        return true;
    }
    if (!my_strcmp(line, "##end\n")) {
        stock_end(var);
        return true;
    }
    return false;
}
