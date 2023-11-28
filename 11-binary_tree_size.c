#include "binary_trees.h"
/**
 * binary_tree_size -  measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: size of tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;
	const binary_tree_t *current;

	if (tree == NULL)
		return (0);
	current = tree;
	while (current->right != NULL)
	{
		if (current->left != NULL)
		{
			size++;
			current = current->left;
		}
		if (current->right != NULL)
		{
			size++;
			current = current->right;
		}
	}
	while (tree->left != NULL)
	{
		if (tree->left != NULL)
		{
			size++;
			tree = tree->left;
		}
		if (tree->right != NULL)
		{
			size++;
			tree = tree->right;
		}
	}
	return (size);
}
