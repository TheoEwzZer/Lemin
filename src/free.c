/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

void free_path_table(var_t *var)
{
    for (size_t i = 0; var->paths[i]; i++) {
        node_t *current = var->paths[i]->head;
        while (current) {
            node_t *next = current->next;
            free(current);
            current = next;
        }
        free(var->paths[i]);
    }
    free(var->paths);
}

void free_list(list_t *list)
{
    node_t *current = list->head;
    node_t *tmp = NULL;

    while (current) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    list->head = NULL;
    list->tail = NULL;
}

void remove_from_path(node_t **current, list_t *list, char *data)
{
    if ((*current)->data == data) {
        if ((*current)->prev) {
            (*current)->prev->next = (*current)->next;
        }
        if ((*current)->next) {
            (*current)->next->prev = (*current)->prev;
        }
        if (*current == list->head) {
            list->head = (*current)->next;
        }
        if (*current == list->tail) {
            list->tail = (*current)->prev;
        }
        free(*current);
        *current = NULL;
        return;
    }
    *current = (*current)->next;
}
