#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t size = 0;
    const binary_tree_t *current = tree;
    const binary_tree_t *predecessor = NULL;

    while (current)
    {
        if (!current->left)
        {
            size++;
            current = current->right;
        }
        else
        {
            predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
                predecessor = predecessor->right;

            if (!predecessor->right)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                size++;
                current = current->right;
            }
        }
    }

    return size;
}

