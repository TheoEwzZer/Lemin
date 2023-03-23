/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

char *getroom_tunnel(char *input)
{
    char *room = NULL;
    unsigned int end_room = 0;
    unsigned int len = my_strlen(input);

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

char *getroom2(unsigned int end_room, char *input,
unsigned int num_words, bool new)
{
    unsigned int len = my_strlen(input);
    char *room = malloc(sizeof(char) * (end_room + 1));
    my_strncpy(room, input, end_room);
    room[end_room] = '\0';
    for (unsigned int i = 0; i < len; i++) {
        if (input[i] == ' ' || input[i] == '-' || input[i] == '\n') {
            new = true;
        } if (new && input[i] != ' ' && input[i] != '-' && input[i] != '\n') {
            num_words++;
            new = false;
        } if (input[i] == '#') {
            num_words--;
            break;
        }
    }
    if (num_words != 3) {
        free(room);
        return NULL;
    }
    return room;
}

char *getroom(char *input)
{
    unsigned int end_room = 0;
    unsigned int len = my_strlen(input);
    unsigned int num_words = 0;
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

    if (!data) {
        write(2, "Error: Invalid room.\n", 21);
        return 84;
    }
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
