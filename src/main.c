/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void init(var_t *var)
{
    init_list(&var->path);
    var->path_count = 0;
    var->room_nb = 0;
    var->output = malloc(sizeof(char) * BUFFER_SIZE);
    var->tunnel_nb = 0;
    var->room = NULL;
    var->check_tunnels = false;
    for (size_t i = 0; i < BUFFER_SIZE; i++)
        var->output[i] = '\0';
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    size_t path_capacity = 100;

    init(var);
    if (argc != 1) {
        write(2, "Error: Invalid number of arguments.\n", 36);
        return 84;
    }
    if (read_file(var) == 84)
        return 84;
    my_putstr(var->output);
    var->paths = malloc(sizeof(list_t *) * path_capacity);
    for (size_t i = 0; i < path_capacity; i++)
        var->paths[i] = NULL;
    dfs(var->graph, var);
    sort_paths(var);
    print_paths(var);
    send_ants(var);
    free_path_table(var);
    return 0;
}
