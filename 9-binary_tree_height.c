#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);
	while (tree->left != NULL || tree->right != NULL)
	{
		if (tree->left != NULL)
		{
			height++;
			tree = tree->left;
		}
		else if (tree->right != NULL)
		{
			height++;
			tree = tree->right;
		}
	}
	return (height);
}
