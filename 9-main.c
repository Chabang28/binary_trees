#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "queue.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t height = 0;
    queue_t *queue = NULL;

    queue_push(&queue, (void *)tree);

    while (queue)
    {
        size_t level_size = queue_size(queue);
        for (size_t i = 0; i < level_size; i++)
        {
            binary_tree_t *node = (binary_tree_t *)queue->node;
            queue_pop(&queue);

            if (node->left)
                queue_push(&queue, (void *)node->left);
            if (node->right)
                queue_push(&queue, (void *)node->right);
        }
        height++;
    }

    return height - 1; // Subtract 1 to account for the root level
}

