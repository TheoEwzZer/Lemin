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

int create_rooms(var_t *var, int data)
{
    link_t **new_rooms = NULL;

    for (unsigned int i = 0; var->room && var->room[i]; i++) {
        if (var->room[i]->data == data)
            return 84;
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

int link_parsing(var_t *var, char *line)
{
    link_t *link1 = NULL;
    link_t *link2 = NULL;

    if (!line || !var->room)
        return 84;
    for (unsigned int i = 0; var->room[i]; i++) {
        if (var->room[i]->data == my_getnbr(line))
            link1 = var->room[i];
        if (var->room[i]->data == my_getnbr(line + 2))
            link2 = var->room[i];
    }
    if (links(var, link1, link2) == 84)
        return 84;
    return 0;
}

int read_file2(var_t *var, char *line)
{
    int stock = check_stock(var, line);
    bool check_tunnels = false;

    if (stock == 84)
        return 84;
    if (stock == 1 || line[0] == '#')
        return 0;
    if (line[1] == '-' && !check_tunnels) {
        my_strcat(var->output, "#tunnels\n");
        check_tunnels = true;
    }
    my_strcat_ignore_hash(var->output, line);
    if (!check_tunnels) {
        if (create_rooms(var, my_getnbr(line)) == 84)
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
        var->number_of_ants = my_getnbr(line);
        if (var->number_of_ants <= 0)
            return 84;
        my_strcat(var->output, "#number_of_ants\n");
        my_strcat(var->output, line);
        my_strcat(var->output, "#rooms\n");
        break;
    }
    while (getline(&line, &size, stdin) != -1) {
        if (read_file2(var, line) == 84)
            return 84;
    }
    if (!var->room_nb || !var->tunnel_nb || !var->graph || !var->end)
        return 84;
    my_strcat(var->output, "\n#moves\n");
    return 0;
}
