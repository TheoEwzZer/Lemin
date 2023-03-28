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
    bool used;
    char *data;
    int ant;
    size_t number_of_ants;
    size_t path_number;
    size_t size;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
} list_t;

typedef struct link {
    bool used;
    bool visited;
    char *data;
    size_t next_nb;
    size_t number_of_ants;
    struct link **next;
} link_t;

typedef struct var {
    bool check_tunnels;
    char *output;
    int **path_assignments;
    int number_of_ants;
    link_t **room;
    link_t *end;
    link_t *graph;
    list_t **paths;
    list_t path;
    unsigned int path_count;
    unsigned int room_nb;
    unsigned int tunnel_nb;
} var_t;

bool is_tunnel(char *line);
char *getroom(char *input);
char *getroom2(size_t end_room, char *input, size_t num_words, bool new);
char *getroom_tunnel(char *input);
char *int_to_str(int nb);
int check_stock(var_t *var, char *line);
int create_rooms(var_t *var, char *data);
int get_info(var_t *var);
int link_parsing(var_t *var, char *line);
int links(var_t *var, link_t *link1, link_t *link2);
int main(int argc, char **argv);
int read_file(var_t *var);
int read_file2(var_t *var, char *line);
int send_ants(var_t *var);
int sort_paths(var_t *var);
int stock_end(var_t *var);
int stock_start(var_t *var);
link_t *create_link(char *data);
void add_to_list(var_t *var, list_t *list, char *data);
void add_to_path(node_t *current, var_t *var);
void choose_path(var_t *var, size_t i);
void dfs(link_t *node, var_t *var);
void dfs2(link_t *node, var_t *var, size_t i);
void free_list(list_t *list);
void free_path_table(var_t *var);
void init(var_t *var);
void init_list(list_t *list);
void move_in_path(var_t *var, node_t *current, size_t i);
void my_strcat_ignore_hash(char *dest, const char *src);
void print_ants(var_t *var);
void print_data_of_connected_links(link_t* link);
void print_moves(var_t *var);
void print_paths(var_t *var);
void remove_from_path(node_t **current, list_t *list, char *data);
void reset_used(var_t *var);
void swap(var_t *var, size_t j);
void travel(var_t *var, size_t i, size_t j, node_t *current);
void update(var_t *var, node_t *current);

#endif /* MYSH_H_ */
