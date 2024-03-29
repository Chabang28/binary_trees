#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of a given node
 * @parent: A pointer to the parent node
 * @value: Value to be stored in the new node
 *
 * Return: A pointer to the newly inserted left child, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL) {
        return NULL; // Insertion not allowed if parent node is NULL
    }

    binary_tree_t *new_node = binary_tree_node(parent, value);
    if (new_node == NULL) {
        return NULL; // Memory allocation failed
    }

    if (parent->left != NULL) {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }

    parent->left = new_node;

    return new_node;
}

