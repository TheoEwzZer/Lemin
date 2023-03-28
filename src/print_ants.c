/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void update(var_t *var, node_t *current)
{
    current->next->used = true;
    if (current->next->data == var->end->data)
        var->end->number_of_ants++;
    my_strcat(var->output, "P");
    my_strcat(var->output, int_to_str(current->next->ant));
    my_strcat(var->output, "-");
    my_strcat(var->output, current->next->data);
    my_strcat(var->output, " ");
}

void travel(var_t *var, size_t i, size_t j, node_t *current)
{
    if (current->number_of_ants > 0 && current->next
    && current->next->ant == -1 && !current->used) {
        current->next->number_of_ants++;
        current->number_of_ants--;
        if (current->data == var->graph->data
        && var->path_assignments[i][j] != -1) {
            current->next->ant = var->path_assignments[i][j] + 1;
            var->path_assignments[i][j] = -1;
            update(var, current);
            return;
        }
        if (current->ant != -1) {
            current->next->number_of_ants++;
            current->next->ant = current->ant;
            current->ant = -1;
            update(var, current);
        }
    }
}

void move_in_path(var_t *var, node_t *current, size_t i)
{
    for (size_t j = 0; j < (size_t)var->number_of_ants; j++) {
        if (var->path_assignments[i][j] == -1
        && var->paths[i]->head->number_of_ants > 0)
            continue;
        current = var->paths[i]->tail;
        while (current) {
            travel(var, i, j, current);
            current = current->prev;
            var->paths[i]->tail->ant = -1;
        }
    }
}

void reset_used(var_t *var)
{
    node_t *current = NULL;

    for (size_t i = 0; i < (size_t)var->path_count; i++) {
        current = var->paths[i]->tail;
        while (current) {
            current->used = false;
            current = current->prev;
        }
    }
}

void print_ants(var_t *var)
{
    node_t *current = NULL;

    while (var->end->number_of_ants < (size_t)var->number_of_ants) {
        for (size_t i = 0; i < (size_t)var->path_count; i++)
            move_in_path(var, current, i);
        my_strcat(var->output, "\n");
        reset_used(var);
    }
}
