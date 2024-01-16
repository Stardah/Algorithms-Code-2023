#pragma once

#include "tree.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct tree_list {
    struct list_node *front;
    struct list_node *back;
} tree_list;

typedef struct list_node {
    struct tree_node *value;
    struct list_node *next;
    struct list_node *prev;
} list_node;

tree_list list_init();
void list_push_back(tree_list *, tree_node *);
void list_push_front(tree_list *, tree_node *);
void list_pop_back(tree_list *);
void list_pop_front(tree_list *);
bool list_is_empty(tree_list *);
void list_free(tree_list *);