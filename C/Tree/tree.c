#include "tree.h"
#include "list.c"
#include "list.h"

#include <stdio.h>
#include <stdlib.h>

tree_node *tree_init_node(int value, const tree_node *parent) {
    tree_node *node = malloc(sizeof(tree_node));
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;
    node->value = value;
    return node;
}

tree_node *tree_find_node(const tree_node *node, int value) {
    if (node->value == value) {
        return node;
    }

    if (value > node->value && node->right != NULL) {
        return tree_find_node(node->right, value);
    } else if (value < node->value && node->left != NULL) {
        return tree_find_node(node->left, value);
    }

    return NULL;
}

tree_node *tree_find_min(const tree_node *node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

tree_node *tree_find_max(const tree_node *node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

void tree_insert(tree_node *node, int value) {
    if (value < node->value) {
        if (!node->left) {
            node->left = tree_init_node(value, node);
        } else {
            tree_insert(node->left, value);
        }
    } else if (node->value < value) {
        if (!node->right) {
            node->right = tree_init_node(value, node);
        } else {
            tree_insert(node->right, value);
        }
    }
}

bool tree_remove_node(tree_node *node, int value) {
    if (!tree_find_node(node, value))
        return false;

       free(node);
    return true;
}

void *free_nodes(tree_node *node) {
    if (node->left) {
        free_nodes(node->left);
    }
    if (node->right) {
        free_nodes(node->right);
    }
    free(node->left);
    free(node->right);
    node->left = NULL;
    node->right = NULL;
}

void tree_free(tree_node *root) {
    free_nodes(root);
    free(root);
    root = NULL;
}

void print_tree_queue(tree_node *node) {
    tree_list list = list_init();

    int i = 0;
    int pow = 1;

    list_push_back(&list, node);
    while (!list_is_empty(&list)) {
        node = list.front->value;
        list_pop_front(&list);
        if (node == NULL)
            continue;

        printf("%d ", node->value);
        i++;

        if (i == pow) {
            printf("\n");
            pow *= 2;
            i = 0;
        }

        list_push_back(&list, node->left);
        list_push_back(&list, node->right);
    }
    list_free(&list);
}

void print_acc(int value, int acc) {
    for (size_t i = 0; i < acc; i++) {
        printf("%c", '-');
    }
    printf("%d\n", value);
}

void print_tree(const tree_node *node, int acc) {
    if (node != NULL) {
        // printf("%d\n", t->value);
        print_acc(node->value, acc);
        print_tree(node->left, acc + 1);
        print_tree(node->right, acc + 1);
    }
}

int main(int argc, char const *argv[]) {
    tree_node *root = tree_init_node(10, NULL);

    tree_insert(root, 5);
    tree_insert(root, 15);
    tree_insert(root, 3);
    tree_insert(root, 0);
    tree_insert(root, 4);
    tree_insert(root, 2);

    print_tree(root, 0);
    print_tree_queue(root);

    tree_free(root);
    return 0;
}
