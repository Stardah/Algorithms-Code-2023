#pragma once

#include "list.c"
#include "list.h"

#include <stdbool.h>
#include <stdint.h>

int_list *init_queue();
int queue_back(int_list *);
int queue_front(int_list *);
void queue_push_back(int_list *, int);
void queue_pop_front(int_list *);
void queue_free(int_list *);