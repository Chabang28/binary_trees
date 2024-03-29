#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root = binary_tree_node(NULL, 98);
    if (root == NULL) {
        return 1;
    }

    root->left = binary_tree_node(root, 12);
    if (root->left == NULL) {
        free(root);
        return 1; 
    }
    root->left->left = binary_tree_node(root->left, 6);
    if (root->left->left == NULL) {
        free(root->left);
        free(root);
        return 1;
    }
    root->left->right = binary_tree_node(root->left, 16);
    if (root->left->right == NULL) {
        free(root->left->left);
        free(root->left);
        free(root);
        return 1;
    }

    root->right = binary_tree_node(root, 402);
    if (root->right == NULL) {
        free(root->left->left);
        free(root->left->right);
        free(root->left);
        free(root);
        return 1;
    }
    root->right->left = binary_tree_node(root->right, 256);
    if (root->right->left == NULL) {
        free(root->left->left);
        free(root->left->right);
        free(root->left);
        free(root->right);
        free(root);
        return 1; 
    }
    root->right->right = binary_tree_node(root->right, 512);
    if (root->right->right == NULL) {
        free(root->left->left);
        free(root->left->right);
        free(root->left);
        free(root->right->left);
        free(root->right);
        free(root);
        return 1;
    }

    binary_tree_print(root);
    return 0;
