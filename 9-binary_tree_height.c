#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		leaves++;
	if (tree->right != NULL)
		leaves++;
	binary_tree_height(tree->left);
	binary_tree_height(tree->right);
	return (leaves);
}
