#pragma once

// #include "list.c"
#include "list.h"

#include <stdbool.h>
#include <stdint.h>

int_list *init_stack();
int stack_back(int_list *);
void stack_push_back(int_list *, int);
void stack_pop_back(int_list *);
void stack_free(int_list *);