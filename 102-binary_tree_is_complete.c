#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	queue_t *queue = NULL;
	int is_complete = 1;
	int seen_null = 0;

	queue = enqueue(queue, (void *)tree);

	while (queue)
	{
		binary_tree_t *node = (binary_tree_t *)dequeue(&queue);

		if (node == NULL)
			seen_null = 1;
		else
		{
			if (seen_null)
			{
				is_complete = 0;
				break;
			}
			queue = enqueue(queue, (void *)node->left);
			queue = enqueue(queue, (void *)node->right);
		}
	}

	free_queue(queue);

	return is_complete;
}

/**
 * enqueue - Enqueues a node in a queue
 *
 * @queue: A pointer to the queue
 * @data: The data to enqueue
 *
 * Return: A pointer to the modified queue
 */
queue_t *enqueue(queue_t *queue, void *data)
{
	queue_t *new_node = malloc(sizeof(queue_t));

	if (!new_node)
		exit(EXIT_FAILURE);

	new_node->data = data;
	new_node->next = NULL;

	if (!queue)
		return new_node;

	queue_t *temp = queue;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return queue;
}

/**
 * dequeue - Dequeues a node from a queue
 *
 * @queue: A pointer to the queue
 *
 * Return: The data of the dequeued node
 */
void *dequeue(queue_t **queue)
{
	if (!(*queue))
		return NULL;

	queue_t *temp = *queue;
	void *data = temp->data;

	*queue = temp->next;
	free(temp);

	return data;
}

/**
 * free_queue - Frees a queue
 *
 * @queue: A pointer to the queue
 */
void free_queue(queue_t *queue)
{
	while (queue)
	{
		queue_t *temp = queue;
		queue = queue->next;
		free(temp);
	}
}

