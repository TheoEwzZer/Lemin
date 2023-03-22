/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

int stock_start(var_t *var)
{
    char *line = NULL;
    size_t size = 0;

    my_strcat(var->output, "##start\n");
    getline(&line, &size, stdin);
    my_strcat(var->output, line);
    if (create_rooms(var, my_getnbr(line)) == 84)
        return 84;
    var->graph = var->room[var->room_nb - 1];
    return 0;
}

int stock_end(var_t *var)
{
    char *line = NULL;
    size_t size = 0;

    my_strcat(var->output, "##end\n");
    getline(&line, &size, stdin);
    my_strcat(var->output, line);
    if (create_rooms(var, my_getnbr(line)) == 84)
        return 84;
    var->end = var->room[var->room_nb - 1];
    var->end_data = my_getnbr(line);
    return 0;
}

int check_stock(var_t *var, char *line)
{
    if (!my_strncmp(line, "##start", 7)) {
        if (stock_start(var) == 84)
            return 84;
        return 1;
    }
    if (!my_strncmp(line, "##end", 5)) {
        if (stock_end(var) == 84)
            return 84;
        return 1;
    }
    return 0;
}
