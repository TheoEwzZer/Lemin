/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void init_list(list_t *list)
{
    list->head = NULL;
    list->tail = NULL;
}

void add_to_list(list_t *list, char *data)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->prev = list->tail;
    node->next = NULL;
    if (!list->tail)
        list->head = node;
    else
        list->tail->next = node;
    list->tail = node;
}

void dfs2(link_t *node, var_t *var, size_t i)
{
    if (!node->next[i]->visited && !node->next[i]->used) {
        if (node->next[i] != var->graph && node->next[i] != var->end)
            node->next[i]->used = true;
        dfs(node->next[i], var);
    }
}

void add_to_path(node_t *current, var_t *var)
{
    add_to_list(var->paths[var->path_count], var->graph->data);
    while (current) {
        if (current->data != var->graph->data)
            add_to_list(var->paths[var->path_count], current->data);
        current = current->next;
    }
}

void dfs(link_t *node, var_t *var)
{
    node_t *current = NULL;

    node->visited = true;
    add_to_list(&var->path, node->data);
    if (node == var->end) {
        var->paths[var->path_count] = malloc(sizeof(list_t));
        init_list(var->paths[var->path_count]);
        current = var->path.head;
        add_to_path(current, var);
        (var->path_count)++;
        free(var->path.head);
    }
    for (size_t i = 0; i < node->next_nb; i++)
        dfs2(node, var, i);
    node->visited = false;
}
