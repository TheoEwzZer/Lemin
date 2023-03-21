/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

void my_putstr_ignore_hash(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' && str[i + 1] && str[i + 1] == '#') {
            write(1, "\n", 1);
            break;
        }
        write(1, &str[i], 1);
    }
}

void create_rooms(var_t *var)
{
    link_t **new_rooms;
    new_rooms = malloc(sizeof(link_t *) * (unsigned long)(var->room_nb + 1));
    for (unsigned int i = 0; i < var->room_nb; i++)
        new_rooms[i] = var->room[i];
    new_rooms[var->room_nb] = create_link((int)var->room_nb);
    var->room_nb++;
    var->room = new_rooms;
}

void read_file2(var_t *var, char *line, size_t size, bool check_tunnels)
{
    while (getline(&line, &size, stdin) != -1) {
        if (line[0] == '#' && line[1] != '#')
            continue;
        if (line[1] == '-' && !check_tunnels) {
            write(1, "#tunnels\n", 9);
            check_tunnels = true;
        }
        my_putstr_ignore_hash(line);
        if (line[0] == '#')
            continue;
        if (!check_tunnels) {
            create_rooms(var);
        } else
            links(var->room[my_getnbr(line)], var->room[my_getnbr(line + 2)]);
    }
}

void read_file(var_t *var)
{
    char *line = NULL;
    size_t size = 0;
    bool check_tunnels = false;
    while (getline(&line, &size, stdin) != -1) {
        var->number_of_ants = (unsigned int)my_getnbr(line);
        write(1, "#number_of_ants\n", 16);
        my_put_nbr(var->number_of_ants, 0);
        write(1, "\n#rooms\n", 8);
        break;
    }
    read_file2(var, line, size , check_tunnels);
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));
    var->room_nb = 0;

    if (argc != 1)
        return 84;
    read_file(var);
    return 0;
}
