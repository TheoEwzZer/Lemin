/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

int link_parsing(var_t *var, char *line)
{
    link_t *link1 = NULL;
    link_t *link2 = NULL;
    char *room = getroom_tunnel(line);
    char *room2 = getroom_tunnel(line + my_strlen(room) + 1);

    if (!line || !var->room || !room || !room2)
        return 84;
    for (size_t i = 0; var->room[i]; i++) {
        if (!my_strcmp(var->room[i]->data, room))
            link1 = var->room[i];
        if (!my_strcmp(var->room[i]->data, room2))
            link2 = var->room[i];
    }
    if (links(var, link1, link2) == 84)
        return 84;
    if (links(var, link2, link1) == 84)
        return 84;
    return 0;
}
