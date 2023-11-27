#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct int_list {
    struct list_node *front;
    struct list_node *back;
} int_list;

typedef struct list_node {
    int value;
    struct list_node *next;
    struct list_node *prev;
} list_node;

/// Создание нового узла на куче
list_node *list_node_init(int);

/// Создание списка на стеке
int_list list_init(void);

/// Добавление элемента в конец
void list_push_back(int_list *, int value);

/// Добавление элемента в начало
void list_push_front(int_list *, int value);

/// Удаление элемента с конца
void list_pop_back(int_list *);

/// Удаление элемента с начала
void list_pop_front(int_list *);

/// Проверка на пустоту
bool list_is_empty(int_list *);

/// Освобождение памяти
void list_free(int_list *);