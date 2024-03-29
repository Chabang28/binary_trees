}#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 10);
    root->left = binary_tree_node(root, 5);
    root->right = binary_tree_node(root, 20);
    root->right->left = binary_tree_node(root->right, 15);
    root->right->right = binary_tree_node(root->right, 25);

    binary_tree_print(root);
    printf("Rotate-left %d\n", root->n);
    root = binary_tree_rotate_left(root);
    binary_tree_print(root);
    printf("\n");

    root->left->left = binary_tree_node(root->left, 2);
    root->left->right = binary_tree_node(root->left, 7);
    binary_tree_print(root);
    printf("Rotate-left %d\n", root->n);
    root = binary_tree_rotate_left(root);
    binary_tree_print(root);

    /* Clean up */
    binary_tree_delete(root);

    return (0);
}

