/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

link_t *create_link(int data)
{
    link_t *new_link = malloc(sizeof(link_t));

    new_link->data = data;
    new_link->visited = false;
    new_link->next_nb = 0;
    new_link->next = NULL;
    return new_link;
}

void print_data_of_connected_links(link_t* link)
{
    if (!link)
        return;
    write(1, "Data of connected links for link ", 27);
    my_put_nbr(link->next_nb, 0);
    write(1, ":\n", 2);
    for (unsigned int i = 0; i < link->next_nb; i++) {
        my_put_nbr(link->next[i]->data, 0);
        write(1, "\n", 1);
    }
}

void links(link_t *link1, link_t *link2)
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
