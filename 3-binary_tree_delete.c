#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	/*Recursively call (root)tree->left until it is NULL*/
	binary_tree_delete(tree->left);
	/*Recursively call (root)tree->right until it is NULL*/
	binary_tree_delete(tree->right);
	/*Free allocated memory*/
	free(tree);
}
