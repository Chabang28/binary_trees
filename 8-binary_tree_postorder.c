#include "binary_trees.h"
#include "stack.h"

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    stack_t *stack = NULL;
    const binary_tree_t *current = tree;
    const binary_tree_t *prev = NULL;

    do {
        while (current) {
            stack_push(&stack, (void *)current);
            current = current->left;
        }

        while (!current && stack) {
            current = (const binary_tree_t *)stack_peek(stack);

            if (current->right && current->right != prev)
                current = current->right;
            else {
                func(current->n);
                stack_pop(&stack);
                prev = current;
                current = NULL;
            }
        }
    } while (stack);
}

