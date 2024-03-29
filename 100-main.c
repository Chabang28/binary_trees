#include "binary_trees.h"

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

    const binary_tree_t *node1 = first;
    const binary_tree_t *node2 = second;

  
    int depth1 = 0;
    while (node1) {
        node1 = node1->parent;
        depth1++;
    }

   
    int depth2 = 0;
    while (node2) {
        node2 = node2->parent;
        depth2++;
    }

  
    node1 = first;
    node2 = second;
    while (depth1 > depth2) {
        node1 = node1->parent;
        depth1--;
    }
    while (depth2 > depth1) {
        node2 = node2->parent;
        depth2--;
    }

   
    while (node1 && node2) {
        if (node1 == node2)
            return (binary_tree_t *)node1;
        node1 = node1->parent;
        node2 = node2->parent;
    }

    return NULL 1;
}

