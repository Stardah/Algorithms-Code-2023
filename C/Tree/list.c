#include "list.h"

#include <stdlib.h>

tree_list list_init() {
    tree_list list = {
        .front = NULL,
        .back = NULL};
    return list;
}

list_node *init_node(tree_node *value) {
    list_node *new_node = malloc(sizeof(list_node));
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;
    return new_node;
}

void list_push_back(tree_list *list, tree_node *value) {
    list_node *node = init_node(value);
    if (list->back == NULL && list->front == NULL) {
        list->back = node;
        list->front = node;
        return;
    }

    node->prev = list->back;
    list->back->next = node;
    list->back = node;
}

void list_push_front(tree_list *list, tree_node *value) {
    list_node *node = init_node(value);
    if (list->back == NULL && list->front == NULL) {
        list->back = node;
        list->front = node;
        return;
    }

    node->next = list->front;
    list->front->prev = node;
    list->front = node;
}

void list_pop_back(tree_list *list) {
    if (list->back == NULL) {
        return;
    }

    if (list->back->prev == NULL) {
        free(list->back);
        list->back = NULL;
        list->front = NULL;
    } else {
        list_node *ptr = list->back;
        list->back = list->back->prev;
        list->back->next = NULL;
        free(ptr);
    }
}

void list_pop_front(tree_list *list) {
    if (list->front == NULL) {
        return;
    }

    if (list->front->next == NULL) {
        free(list->front);
        list->back = NULL;
        list->front = NULL;
    } else {
        list_node *ptr = list->front;
        list->front = list->front->next;
        list->front->prev = NULL;
        free(ptr);
    }
}

bool list_is_empty(tree_list *list) {
    return (list->back == NULL) && (list->front == NULL);
}

void list_free(tree_list *list) {
    list_node *ptr = list->front;
    while (ptr != NULL) {
        list_node *node = ptr;
        ptr = ptr->next;
        free(node);
    }
}

void print_list(list_node *head) {
    list_node *ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
}