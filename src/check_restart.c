/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

link_t *check_restart(var_t *var, link_t *node)
{
    bool can_restart = true;

    for (size_t i = 0; var->graph->next[i]; i++) {
        if (var->graph->next[i] == var->end) {
            can_restart = false;
            break;
        }
    }
    if (can_restart)
        node = var->graph;
    return node;
}
