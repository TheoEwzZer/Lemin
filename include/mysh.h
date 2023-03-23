/*
** EPITECH PROJECT, 2023
** lemin
** File description:
** Ant-based calculation unit
*/

#ifndef MYSH_H_

    #define MYSH_H_

    #include "my.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define BUFFER_SIZE 150000

typedef struct link {
    bool visited;
    char *data;
    struct link **next;
    unsigned int next_nb;
} link_t;

typedef struct var {
    bool check_tunnels;
    char *output;
    int number_of_ants;
    link_t **room;
    link_t *end;
    link_t *graph;
    unsigned int room_nb;
    unsigned int tunnel_nb;
} var_t;

bool is_tunnel(char *line);
char *getroom(char *input);
char *getroom2(unsigned int end_room, char *input,
unsigned int num_words, bool new_word);
char *getroom_tunnel(char *input);
int check_stock(var_t *var, char *line);
int create_rooms(var_t *var, char *data);
int link_parsing(var_t *var, char *line);
int links(var_t *var, link_t *link1, link_t *link2);
int read_file(var_t *var);
int read_file2(var_t *var, char *line);
int stock_end(var_t *var);
int stock_start(var_t *var);
link_t *create_link(char *data);
void my_strcat_ignore_hash(char *dest, const char *src);
void print_data_of_connected_links(link_t* link);

#endif /* MYSH_H_ */
