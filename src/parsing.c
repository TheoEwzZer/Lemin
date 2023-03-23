/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

void my_strcat_ignore_hash(char *dest, const char *src)
{
    unsigned int dest_len = my_strlen(dest);
    unsigned int src_len = my_strlen(src);
    unsigned int i = 0;

    for (; i < src_len; i++) {
        if (src[i] == ' ' && src[i + 1] == '#') {
            dest[dest_len + i] = '\n';
            dest[dest_len + i + 1] = '\0';
            return;
        }
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
}

int link_parsing(var_t *var, char *line)
{
    link_t *link1 = NULL;
    link_t *link2 = NULL;
    char *room = getroom(line);
    char *room2 = getroom(line + my_strlen(room) + 1);

    if (!line || !var->room) {
        write(2, "Error: Invalid link.\n", 21);
        return 84;
    }
    for (unsigned int i = 0; var->room[i]; i++) {
        if (!my_strcmp(var->room[i]->data, room))
            link1 = var->room[i];
        if (!my_strcmp(var->room[i]->data, room2))
            link2 = var->room[i];
    }
    if (links(var, link1, link2) == 84)
        return 84;
    return 0;
}

bool is_tunnel(char *line)
{
    for (unsigned int i = 0; line[i]; i++) {
        if (line[i] == ' ')
            return false;
        if (line[i] == '-')
            return true;
    }
    return false;
}

int read_file2(var_t *var, char *line)
{
    int stock = check_stock(var, line);

    if (stock == 84)
        return 84;
    if (stock == 1 || line[0] == '#' || line[0] == '\n')
        return 0;
    if (is_tunnel(line) && !var->check_tunnels) {
        my_strcat(var->output, "#tunnels\n");
        var->check_tunnels = true;
    }
    my_strcat_ignore_hash(var->output, line);
    if (!var->check_tunnels) {
        if (create_rooms(var, getroom(line)) == 84)
            return 84;
    } else if (link_parsing(var, line) == 84) {
        return 84;
    }
    return 0;
}

int read_file(var_t *var)
{
    char *line = NULL;
    size_t size = 0;
    while (getline(&line, &size, stdin) != -1) {
        if ((var->number_of_ants = my_getnbr(line)) <= 0) {
            write(2, "Error: Invalid number of ants.\n", 31); return 84;
        }
        my_strcat(var->output, "#number_of_ants\n");
        my_strcat(var->output, line);
        my_strcat(var->output, "#rooms\n");
        break;
    }
    while (getline(&line, &size, stdin) != -1) {
        if (read_file2(var, line) == 84)
            return 84;
    } if (!var->room_nb || !var->tunnel_nb || !var->graph || !var->end) {
        write(2, "Error: Invalid file.\n", 21); return 84;
    } if (var->output[my_strlen(var->output) - 1] != '\n')
        my_strcat(var->output, "\n");
    my_strcat(var->output, "#moves\n");
    return 0;
}
