#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Binary tree node structure */
typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Function prototypes */
size_t binary_tree_depth(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);

/**
 * binary_tree_depth - Calculate the depth of a node in a binary tree.
 * @tree: Pointer to the node.
 *
 * Return: Depth of the node, or 0 if the tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree != NULL)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth - 1); /* Depth of the root is 0 */
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    /* Create a binary tree */
    root = binary_tree_node(NULL, 98);
    if (root == NULL)
        return (1);
    root->left = binary_tree_node(root, 12);
    if (root->left == NULL)
        return (1);
    root->right = binary_tree_node(root, 402);
    if (root->right == NULL)
        return (1);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    
    /* Print the binary tree */
    binary_tree_print(root);

    /* Calculate and print depths */
    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth of %d: %lu\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth of %d: %lu\n", root->left->right->n, depth);

    /* Clean up */
    free(root->left->right);
    free(root->right);
    free(root->left);
    free(root);

    return (0);
}

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to put in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node;

    node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        return (NULL);

    node->n = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    return (node);
}

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node.
 * @parent: Pointer to the parent node.
 * @value: Value to put in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
void binary_tree_insert_right(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return;

    parent->right = binary_tree_node(parent, value);
}

/**
 * binary_tree_print - Prints a binary tree.
 * @tree: Pointer to the root node of the tree to print.
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    printf("%d\n", tree->n);
    binary_tree_print(tree->left);
    binary_tree_print(tree->right);
}

