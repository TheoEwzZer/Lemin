/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

link_t *create_link(char *data)
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
    write(1, "Data of connected links for link ", 33);
    write(1, link->data, my_strlen(link->data));
    write(1, ":\n", 2);
    for (unsigned int i = 0; i < link->next_nb; i++) {
        write(1, link->next[i]->data, my_strlen(link->next[i]->data));
        write(1, "\n", 1);
    }
}

int links(var_t *var, link_t *link1, link_t *link2)
{
    link_t **new_next = NULL;

    if (!link1) {
        write(2, "Error: Try to link a room that doesn't exist.\n", 46);
        return 84;
    }
    if (!link2) {
        write(2, "Error: Try to link to a room that doesn't exist.\n", 49);
        return 84;
    }
    if (!my_strcmp(link1->data, link2->data)) {
        write(2, "Error: Link to itself.\n", 23);
        return 84;
    }
    new_next = malloc(sizeof(link_t *) * (unsigned long)(link1->next_nb + 2));
    for (unsigned int i = 0; i < link1->next_nb; i++)
        new_next[i] = link1->next[i];
    new_next[link1->next_nb] = link2;
    new_next[link1->next_nb + 1] = NULL;
    link1->next = new_next;
    link1->next_nb++;
    var->tunnel_nb++;
    return 0;
}
