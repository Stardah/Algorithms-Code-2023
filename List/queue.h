#pragma once

#include "list.h"
// #include "list.c"

#include <stdint.h>
#include <stdbool.h>

int_list* init_queue();
int queue_back(int_list *);
int queue_front(int_list *);
void queue_push_back(int_list *, int);
void queue_pop_front(int_list *);
void queue_free(int_list *);