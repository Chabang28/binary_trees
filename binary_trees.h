#include "binary_trees.h"
#include <stdbool.h>
#include <limits.h>

int binary_tree_is_bst(const binary_tree_t *tree) {
    if (!tree)
        return 1;
    
    const binary_tree_t *current = tree;
    const binary_tree_t *stack[1024] 
    int top = -1;
    int prev = INT_MIN;

    while (current || top != -1) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        if (current->n <= prev)
            return 0;
        prev = current->n;
        current = current->right;
    }

    return 1;
}

