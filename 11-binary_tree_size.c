#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "queue.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t size = 0;
    queue_t *queue = NULL;

    queue_push(&queue, (void *)tree);

    while (queue)
    {
        const binary_tree_t *node = (const binary_tree_t *)queue->node;
        queue_pop(&queue);
        size++;

        if (node->left)
            queue_push(&queue, (void *)node->left);
        if (node->right)
            queue_push(&queue, (void *)node->right);
    }

    return size;
}

