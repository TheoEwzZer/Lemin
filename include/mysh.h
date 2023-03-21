/*
** EPITECH PROJECT, 2023
** mysh.h
** File description:
** mysh
*/

#ifndef MYSH_H_

    #define MYSH_H_

    #include "my.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

typedef struct link {
    int data;
    struct link **next;
    unsigned int next_nb;
} link_t;

typedef struct var {
    link_t **rooms;
    link_t *graph;
    unsigned int number_of_ants;
    unsigned int room_nb;
} var_t;

link_t *create_link(int data);
void connect_links(link_t *link1, link_t *link2);
void my_putstr_ignore_hash(char *str);
void read_file(var_t *var);

#endif /* MYSH_H_ */
