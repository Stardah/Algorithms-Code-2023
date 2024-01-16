#include "list.c"
#include "list.h"
// #include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int_list init_queue() {
    int_list list = {
        .front = NULL,
        .back = NULL,
    };

    return list;
}

int queue_back(int_list *list) {
    return list->back;
}

int queue_front(int_list *list) {
    return list->front;
}

void queue_push_back(int_list *list, int value) {
    list_push_back(list, value);
}

void queue_pop_front(int_list *list) {
    list_pop_front(list);
}

void queue_free(int_list *list) {
    list_free(list);
}

int main(int argc, char const *argv[]) {
    return 0;
}
