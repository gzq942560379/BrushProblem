//
// Created by gzq on 2019/7/18.
//

#ifndef BRUSHPROBLEM_LIST_H
#define BRUSHPROBLEM_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    void *val;
    struct Node *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
    size_t size;
} list_t;

int list_size(list_t *list);

void list_init(list_t *list);

void list_destroy(list_t *list);

void list_push(list_t *list, void *val);

void *list_top(list_t *list);

void *list_pop(list_t *list);

void list_append(list_t *list, void *val);

void list_print(list_t *list);

#endif //BRUSHPROBLEM_LIST_H
