#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_double - Prints double of a number
 *
 * @n: Number to be printed
 */
void print_double(int n)
{
    printf("%d\n", n * 2);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 5);
    root->left = binary_tree_node(root, 3);
    root->right = binary_tree_node(root, 7);
    root->left->left = binary_tree_node(root->left, 2);
    root->left->right = binary_tree_node(root->left, 4);
    root->right->left = binary_tree_node(root->right, 6);
    root->right->right = binary_tree_node(root->right, 8);

    binary_tree_print(root);
    binary_tree_levelorder(root, &print_double);
    binary_tree_delete(root);
    return (0);
}

