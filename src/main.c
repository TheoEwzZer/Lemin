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
    var->error = false;
    var->path_count = 0;
    var->room_nb = 0;
    var->output = malloc(sizeof(char) * BUFFER_SIZE);
    var->tunnel_nb = 0;
    var->room = NULL;
    var->check_tunnels = false;
    var->graph = NULL;
    for (size_t i = 0; i < BUFFER_SIZE; i++)
        var->output[i] = '\0';
}

void print_moves(var_t *var)
{
    for (size_t i = 0; var->output[i]; i++) {
        if (var->output[i] == ' ' && var->output[i + 1] == '\n')
            continue;
        write(1, &var->output[i], 1);
    }
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    size_t path_capacity = 100; (void)argv;
    init(var);
    if (argc != 1)
        return 84;
    read_file(var);
    my_putstr(var->output);
    free(var->output);
    if (var->error)
        return 84;
    var->output = malloc(sizeof(char) * BUFFER_SIZE);
    for (size_t i = 0; i < BUFFER_SIZE; var->output[i] = '\0', i++);
    var->paths = malloc(sizeof(list_t *) * path_capacity);
    for (size_t i = 0; i < path_capacity; var->paths[i] = NULL, i++);
    dfs(var->graph, var);
    if (sort_paths(var) == 84)
        return 84;
    print_moves(var);
    free_path_table(var);
    return 0;
}
