#include "binary_trees.h"

/**
 * find_common_ancestor - Helper function to find common ancestor recursively
 *
 * @root: The root of the binary tree
 * @node1: First node
 * @node2: Second node
 *
 * Return: The lowest common ancestor or NULL if not found
 */
binary_tree_t *find_common_ancestor(const binary_tree_t *root,
                                     const binary_tree_t *node1,
                                     const binary_tree_t *node2) {
    if (root == NULL || node1 == NULL || node2 == NULL)
        return NULL;

    if (root == node1 || root == node2)
        return (binary_tree_t *)root;

    binary_tree_t *left = find_common_ancestor(root->left, node1, node2);
    binary_tree_t *right = find_common_ancestor(root->right, node1, node2);

    if (left != NULL && right != NULL)
        return (binary_tree_t *)root;

    return (left != NULL ? left : right);
}

/**
 * binary_trees_ancestor - A function that finds the lowest
 * common ancestor of two nodes
 *
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second) {
    if (first == NULL || second == NULL)
        return NULL;

    return find_common_ancestor(first, second, second->parent);
}

