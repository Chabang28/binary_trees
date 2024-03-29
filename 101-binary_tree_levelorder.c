#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - A function that traverses the binary
 * tree using level order traversal
 *
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue for level order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return;

	int front = 0, rear = 0;
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		/* Process current node */
		func(current->n);

		/* Enqueue left child if exists */
		if (current->left != NULL)
			queue[rear++] = current->left;

		/* Enqueue right child if exists */
		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}

