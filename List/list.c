#include "list.h"

#include <stdio.h>
#include <stdlib.h>

int_list list_init(void) {
    int_list list = {
        .front = NULL,
        .back = NULL};
    return list;
}

list_node *list_node_init(int value) {
}

void list_push_back(int_list *list, int value) {
}

void list_push_front(int_list *list, int value) {
}

void list_pop_back(int_list *list) {
}

void list_pop_front(int_list *list) {
}

bool list_is_empty(int_list *list) {
}

void list_free(int_list *list) {
}

void print_list(list_node *head) {
}