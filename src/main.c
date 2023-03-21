/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** lemin
*/

#include "mysh.h"

void my_putstr_ingnore_hash(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' && str[i + 1] && str[i + 1] == '#') {
            write(1, "\n", 1);
            break;
        }
        write(1, &str[i], 1);
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
    while (getline(&line, &size, stdin) != -1) {
        if (line[0] == '#' && line[1] != '#')
            continue;
        if (line[1] == '-' && !check_tunnels) {
            write(1, "#tunnels\n", 9);
            check_tunnels = true;
        }
        my_putstr_ingnore_hash(line);
    }
    write(1, "\n#moves\n", 8);
}

int main(int argc, char **argv)
{
    var_t *var = malloc(sizeof(var_t));

    if (argc != 1)
        return 84;
    read_file(var);
    return 0;
}
