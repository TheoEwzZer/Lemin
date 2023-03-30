/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "lemin.h"

char *getroom_tunnel(char *input)
{
    char *room = NULL;
    size_t end_room = 0;
    size_t len = my_strlen(input);

    if (input[0] == ' ' || input[0] == '-' || input[0] == '\n' || !len)
        return NULL;
    while (end_room < len && input[end_room] != ' '
    && input[end_room] != '-' && input[end_room] != '\n')
        end_room++;
    room = malloc(sizeof(char) * (end_room + 1));
    my_strncpy(room, input, end_room);
    room[end_room] = '\0';
    return room;
}

char *getroom2(size_t endroom, char *input, size_t num_words, bool new)
{
    size_t len = my_strlen(input);
    char *room = malloc(sizeof(char) * (endroom + 1));
    my_strncpy(room, input, endroom);
    room[endroom] = '\0';
    for (size_t i = 0; i < len; i++) {
        if (i > endroom && (input[i] < '0' || input[i] > '9') && input[i] != '-'
        && input[i] != ' ' && input[i] != '\n' && input[i] != '#')
            return NULL;
        if (input[i] == ' ' || input[i] == '-' || input[i] == '\n') {
            new = true;
        } if (new && input[i] != ' ' && input[i] != '-' && input[i] != '\n') {
            num_words++;
            new = false;
        } if (input[i] == '#') {
            num_words--;
            break;
        }
    } if (num_words != 3)
        room = NULL;
    return room;
}

char *getroom(char *input)
{
    size_t end_room = 0;
    size_t len = my_strlen(input);
    size_t num_words = 0;
    bool new_word = true;

    if (input[0] == ' ' || input[0] == '-' || input[0] == '\n' || !len)
        return NULL;
    while (end_room < len && input[end_room] != ' '
    && input[end_room] != '-' && input[end_room] != '\n') {
        end_room++;
        if (new_word) {
            num_words++;
            new_word = false;
        }
    }
    return getroom2(end_room, input, num_words, new_word);
}

int create_rooms(var_t *var, char *data)
{
    link_t **new_rooms = NULL;

    if (!data)
        return 84;
    for (size_t i = 0; var->room && var->room[i]; i++) {
        if (!my_strcmp(var->room[i]->data, data))
            return 84;
    }
    new_rooms = malloc(sizeof(link_t *) * (unsigned long)(var->room_nb + 2));
    for (size_t i = 0; i < var->room_nb; i++)
        new_rooms[i] = var->room[i];
    new_rooms[var->room_nb] = create_link(data);
    var->room_nb++;
    new_rooms[var->room_nb] = NULL;
    var->room = new_rooms;
    return 0;
}
