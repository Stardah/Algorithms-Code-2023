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
    list_node *new_node = malloc(sizeof(list_node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void list_push_back(int_list *list, int value) {
    list_node *new_node = list_node_init(value);

    if (list_is_empty(list)) {
        list->back = new_node;
        list->front = new_node;
    } else {
        list->back->next = new_node;
        new_node->prev = list->back;
        list->back = new_node;
    }
}

void list_push_front(int_list *list, int value) {
    list_node *new_node = list_node_init(value);

    if (list_is_empty(list)) {
        list->back = new_node;
        list->front = new_node;
    } else {
        list->front->prev = new_node;
        new_node->next = list->front;
        list->front = new_node;
    }
}

void list_pop_back(int_list *list) {
    if (list_is_empty(list)) {
        return;
    }

    if (list->back->prev == NULL) {
        free(list->back);
        list->back = NULL;
        list->front = NULL;
    } else {
        list_node *last = list->back;
        list->back = list->back->prev;
        list->back->next = NULL;
        free(last);
    }
}

void list_pop_front(int_list *list) {
    if (list_is_empty(list)) {
        return;
    }

    if (list->front->next == NULL) {
        free(list->front);
        list->front = NULL;
        list->back = NULL;
    } else {
        list_node *last = list->front;
        list->front = list->front->next;
        list->front->prev = NULL;
        free(last);
    }
}

bool list_is_empty(int_list *list) {
    return (list->back == NULL && list->front == NULL);
}

void list_free(int_list *list) {
    if (!list) {
        return;
    }

    list_node *head = list->front;
    while (head) {
        list_node *tmp = head;
        head = head->next;
        free(tmp);
    }
    list->front = NULL;
    list->back = NULL;
}

void print_list(int_list *list) {
    if (!list) {
        return;
    }

    list_node *head = list->front;
    printf("Head");

    while (head) {
        printf("->[%d]", head->value);
        head = head->next;
    }
    printf("->Back");
}