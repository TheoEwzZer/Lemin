/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void swap(var_t *var, size_t j)
{
    list_t *tmp = NULL;

    if (var->paths[j]->head->size > var->paths[j + 1]->head->size) {
        tmp = var->paths[j];
        var->paths[j] = var->paths[j + 1];
        var->paths[j + 1] = tmp;
    }
}

void sort_paths(var_t *var)
{
    list_t *tmp = NULL;

    for (size_t i = 0; i < var->path_count; i++) {
        for (size_t j = 0; j < var->path_count - 1; j++)
            swap(var, j);
    }
}
