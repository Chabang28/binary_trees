#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "stack.h"

void print_postorder(const binary_tree_t *tree)
{
    if (!tree)
        return;

    stack_t *stack1 = NULL;
    stack_t *stack2 = NULL;
    stack_push(&stack1, (void *)tree);

    while (stack1)
    {
        binary_tree_t *node = (binary_tree_t *)stack_pop(&stack1);
        stack_push(&stack2, (void *)node);

        if (node->left)
            stack_push(&stack1, (void *)node->left);
        if (node->right)
            stack_push(&stack1, (void *)node->right);
    }

    while (stack2)
    {
        binary_tree_t *node = (binary_tree_t *)stack_pop(&stack2);
        printf("%d\n", node->n);
    }
}

int main(void)
{
    binary_tree_t *root;

  
    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

   
    binary_tree_print(root);

   
    print_postorder(root);

    return (0);
}

