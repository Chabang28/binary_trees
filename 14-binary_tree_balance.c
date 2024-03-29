#include "binary_trees.h"
/**
 * f_max - find max between two numbers
 * @a: first number
 * @b: second number
 *
 * Return: max
 */
int f_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

/**
 * find_ht - finds the height of a tree
 * @tree: tree to find height of
 *
 * Return: height or 0
 */
size_t find_ht(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	height = f_max(find_ht(tree->left), find_ht(tree->right));

	return (height + 1);
}
/**
 * binary_tree_balance - Measure the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (find_ht(tree->left) - find_ht(tree->right));
}
