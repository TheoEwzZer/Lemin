/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

link_t *create_link(char *data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->data = data;
    new_link->visited = false;
    new_link->used = false;
    new_link->next_nb = 0;
    new_link->next = NULL;
    new_link->number_of_ants = 0;
    return new_link;
}

int links(var_t *var, link_t *link1, link_t *link2)
{
    link_t **new_next = NULL;

    if (!link1 || !link2)
        return 84;
    if (!my_strcmp(link1->data, link2->data))
        return 0;
    new_next = malloc(sizeof(link_t *) * (unsigned long)(link1->next_nb + 2));
    for (size_t i = 0; i < link1->next_nb; i++)
        new_next[i] = link1->next[i];
    new_next[link1->next_nb] = link2;
    new_next[link1->next_nb + 1] = NULL;
    link1->next = new_next;
    link1->next_nb++;
    var->tunnel_nb++;
    return 0;
}
