/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

char *getroom(char *input)
{
    char *room = NULL;
    unsigned int end_room = 0;
    unsigned int len = my_strlen(input);
    unsigned int start_room = 0;

    while (start_room < len && input[start_room] == ' ')
        start_room++;
    if (start_room == len)
        return NULL;
    end_room = start_room;
    while (end_room < len && input[end_room] != ' '
    && input[end_room] != '-' && input[end_room] != '\n')
        end_room++;
    room = malloc(sizeof(char) * (end_room - start_room + 1));
    my_strncpy(room, input + start_room, end_room - start_room);
    room[end_room - start_room] = '\0';
    return room;
}

int create_rooms(var_t *var, char *data)
{
    link_t **new_rooms = NULL;

    for (unsigned int i = 0; var->room && var->room[i]; i++) {
        if (!my_strcmp(var->room[i]->data, data)) {
            write(2, "Error: Room already exists.\n", 28);
            return 84;
        }
    }
    new_rooms = malloc(sizeof(link_t *) * (unsigned long)(var->room_nb + 2));
    for (unsigned int i = 0; i < var->room_nb; i++)
        new_rooms[i] = var->room[i];
    new_rooms[var->room_nb] = create_link(data);
    var->room_nb++;
    new_rooms[var->room_nb] = NULL;
    var->room = new_rooms;
    return 0;
}
