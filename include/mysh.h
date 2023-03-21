#ifndef MYSH_H_

    #define MYSH_H_

    #include "my.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct link {
    bool visited;
    int data;
    struct link **next;
    unsigned int next_nb;
} link_t;

typedef struct var {
    link_t **room;
    link_t *graph;
    unsigned int number_of_ants;
    unsigned int room_nb;
} var_t;

link_t *create_link(int data);
void create_rooms(var_t *var);
void links(link_t *link1, link_t *link2);
void my_putstr_ignore_hash(char *str);
void print_data_of_connected_links(link_t* link);
void read_file(var_t *var);
void read_file2(var_t *var, char *line, size_t size, bool check_tunnels);

#endif /* MYSH_H_ */