#include "binary_trees.h"
#include "stack.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t height = 0;
    const binary_tree_t *current = tree;
    const binary_tree_t *prev = NULL;
    stack_t *stack = NULL;

    while (current || stack)
    {
        while (current)
        {
            stack_push(&stack, (void *)current);
            current = current->left;
        }

        current = (const binary_tree_t *)stack_peek(stack);

        if (current->right && current->right != prev)
            current = current->right;
        else
        {
            if (binary_tree_height(current) > height)
                height = binary_tree_height(current);

            stack_pop(&stack);
            prev = current;
            current = NULL;
        }
    }

    return height + 1;
}

