#include "binary_trees.h"
/**
 * binary_tree_height_left - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of left.
 */
int binary_tree_height_left(const binary_tree_t *tree)
{
	int left_height = 0;

	if (tree == NULL)
		return (0);
	left_height++;
	left_height += binary_tree_height_left(tree->left);
	return (left_height);
}
/**
 * binary_tree_height_right- function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of right.
 */
int binary_tree_height_right(const binary_tree_t *tree)
{
	int right_height = 0;

	if (tree == NULL)
		return (0);
	right_height++;
	right_height += binary_tree_height_right(tree->right);
	return (right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure
 * Return: the balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (binary_tree_height_left(tree) - binary_tree_height_right(tree));
}
