/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void print_paths(var_t *var)
{
    node_t *current = NULL;

    for (size_t i = 0; i < var->path_count; i++) {
        current = var->paths[i]->head;
        while (current->next) {
            my_putstr(current->data);
            write(1, "->", 2);
            current = current->next;
        }
        my_putstr(current->data);
        write(1, "\n", 1);
    }
}
