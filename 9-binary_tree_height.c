#include "binary_trees.h"

/**
 * binary_tree_height_left - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of left.
 */
size_t binary_tree_height_left(const binary_tree_t *tree)
{
	size_t left_height = 0;

	if (tree == NULL)
		return (0);
	left_height += binary_tree_height_left(tree->left) + 1;
	return (left_height);
}
/**
 * binary_tree_height_right- function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of right.
 */
size_t binary_tree_height_right(const binary_tree_t *tree)
{
	size_t right_height = 0;

	if (tree == NULL)
		return (0);
	right_height += binary_tree_height_right(tree->right) + 1;
	return (right_height);
}
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (binary_tree_height_right(tree) <= binary_tree_height_left(tree))
		return (binary_tree_height_left(tree) - 1);
	else
		return (binary_tree_height_right(tree) - 1);
}
