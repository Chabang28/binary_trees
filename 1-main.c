#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    if (root == NULL) {
        return 1;
    }

    root->left = binary_tree_node(root, 12);
    if (root->left == NULL) {
        free(root);
        return 1;
    }

    root->right = binary_tree_node(root, 402);
    if (root->right == NULL) {
        free(root->left);
        free(root);
        return 1;
    }

    binary_tree_print(root);
    printf("\n");

    binary_tree_t *new_left_child = binary_tree_insert_left(root->right, 128);
    if (new_left_child == NULL) {
        free(root->left);
        free(root->right);
        free(root);
        return 1;
    }

    binary_tree_t *new_left = binary_tree_insert_left(root, 54);
    if (new_left == NULL) {
        free(root->left);
        free(root->right);
        free(new_left_child);
        free(root);
        return 1;
    }

    binary_tree_print(root);
    return 0;
}

}
