/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#include "mysh.h"

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    var->room_nb = 0;
    var->output = malloc(sizeof(char) * BUFFER_SIZE);
    var->tunnel_nb = 0;
    var->room = NULL;
    var->check_tunnels = false;
    for (unsigned int i = 0; i < BUFFER_SIZE; i++)
        var->output[i] = '\0';
    if (argc != 1)
        return 84;
    if (read_file(var) == 84)
        return 84;
    my_putstr(var->output);
    return 0;
}
