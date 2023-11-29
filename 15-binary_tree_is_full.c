#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is full otherwise 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	const binary_tree_t *current;

	if (tree == NULL)
		return (0);
	current = tree;
	if (current->right == NULL && current->left == NULL)
		return (1);
	if (current->right != NULL && current->left != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (0);
}
