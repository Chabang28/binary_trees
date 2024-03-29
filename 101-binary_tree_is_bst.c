#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "binary_trees.h"

bool is_bst_util(const binary_tree_t *node, int min, int max)
{
    if (!node)
        return true;

    if (node->n < min || node->n > max)
        return false;

    return is_bst_util(node->left, min, node->n - 1) && is_bst_util(node->right, node->n + 1, max);
}

bool binary_tree_is_bst(const binary_tree_t *tree)
{
    return is_bst_util(tree, INT_MIN, INT_MAX);
}

