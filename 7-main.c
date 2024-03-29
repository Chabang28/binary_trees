#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include "stack.h"

void print_inorder(const binary_tree_t *tree)
{
    if (!tree)
        return;

    stack_t *stack = NULL;
    const binary_tree_t *current = tree;

    while (current || stack)
    {
        while (current)
        {
            stack_push(&stack, (void *)current);
            current = current->left;
        }

        current = (const binary_tree_t *)stack_pop(&stack);
        printf("%d\n", current->n);
        current = current->right;
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

    
    print_inorder(root);

    return (0);
}

