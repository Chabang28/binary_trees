#include "binary_trees.h"
#include <stdio.h>

void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    queue_t *queue = NULL;
    queue_push(&queue, (void *)tree);

    while (queue)
    {
        size_t level_size = queue_size(queue);
        for (size_t i = 0; i < level_size; i++)
        {
            binary_tree_t *node = (binary_tree_t *)queue->node;
            queue_pop(&queue);
            printf("%d ", node->n);

            if (node->left)
                queue_push(&queue, (void *)node->left);
            if (node->right)
                queue_push(&queue, (void *)node->right);
        }
        printf("\n");
    }
}

