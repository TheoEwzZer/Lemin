/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    size_t path_capacity = 100;
    var->path_count = 0;
    var->room_nb = 0;
    var->output = malloc(sizeof(char) * BUFFER_SIZE);
    var->tunnel_nb = 0;
    var->room = NULL;
    var->check_tunnels = false;
    for (size_t i = 0; i < BUFFER_SIZE; i++)
        var->output[i] = '\0';
    if (argc != 1) {
        write(2, "Error: Invalid number of arguments.\n", 36);
        return 84;
    } if (read_file(var) == 84)
        return 84;
    my_putstr(var->output);
    var->paths = malloc(sizeof(list_t *) * path_capacity);
    for (size_t i = 0; i < path_capacity; var->paths[i] = NULL, i++);
    dfs(var->graph, var);
    return 0;
}
