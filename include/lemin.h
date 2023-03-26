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

typedef struct node {
    char *data;
    struct node *prev;
    struct node *next;
    size_t size;
    size_t number_of_ants;
    size_t path_number;
} node_t;

typedef struct list {
    struct node *head;
    struct node *tail;
} list_t;

typedef struct link {
    bool visited;
    char *data;
    size_t next_nb;
    struct link **next;
    bool used;
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
    list_t path;
    list_t **paths;
    unsigned int path_count;
} var_t;

bool is_tunnel(char *line);
char *getroom(char *input);
char *getroom2(size_t end_room, char *input, size_t num_words, bool new);
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
void add_to_list(var_t *var, list_t *list, char *data);
void add_to_path(node_t *current, var_t *var);
void dfs(link_t *node, var_t *var);
void dfs2(link_t *node, var_t *var, size_t i);
void init_list(list_t *list);
void my_strcat_ignore_hash(char *dest, const char *src);
void print_data_of_connected_links(link_t* link);
void print_paths(var_t *var);
void sort_paths(var_t *var);

#endif /* MYSH_H_ */
