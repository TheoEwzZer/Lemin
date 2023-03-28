/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void choose_path(var_t *var, size_t i)
{
    size_t smallest_path = 0;
    node_t *path1 = NULL, *path2 = NULL;
    size_t size1 = 0, size2 = 0;

    for (size_t j = 0; j < var->path_count; j++) {
        path1 = var->paths[j]->head;
        path2 = var->paths[smallest_path]->head;
        size1 = path1->size - 2 + path1->number_of_ants;
        size2 = path2->size - 2 + path2->number_of_ants;
        if (size1 < size2)
            smallest_path = j;
    }
    for (size_t j = 0; j < (size_t)var->number_of_ants; j++) {
        if (var->path_assignments[smallest_path][j] == -1) {
            var->path_assignments[smallest_path][j] = (int)i;
            break;
        }
    }
    if (var->paths[smallest_path])
        var->paths[smallest_path]->head->number_of_ants++;
}

int send_ants(var_t *var)
{
    var->path_assignments = malloc(sizeof(int *) * (size_t)var->path_count);

    for (size_t i = 0; i < (size_t)var->path_count; i++) {
        var->path_assignments[i] = malloc(
            sizeof(int) * (size_t)var->number_of_ants
        );
        for (size_t j = 0; j < (size_t)var->number_of_ants; j++)
            var->path_assignments[i][j] = -1;
    }
    if (!var->paths[0])
        return 84;
    for (size_t i = 0; i < (size_t)var->number_of_ants; i++)
        choose_path(var, i);
    print_ants(var);
    return 0;
}
