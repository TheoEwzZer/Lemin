/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** lemin
*/

#include "mysh.h"

link_t *create_link(int data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->data = data;
    new_link->next_nb = 0;
    new_link->next = NULL;
    return new_link;
}

void connect_links(link_t *link1, link_t *link2)
{
    link_t **new_next = NULL;
    if (!link1 || !link2)
        return;
    new_next = malloc(sizeof(link_t *) * (unsigned long)(link1->next_nb + 1));
    for (unsigned int i = 0; i < link1->next_nb; i++)
        new_next[i] = link1->next[i];
    new_next[link1->next_nb] = link2;
    link1->next = new_next;
    link1->next_nb++;
}
