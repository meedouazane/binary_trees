#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: height of tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left) + 1;
	else
		left_height = 1;
	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right) + 1;
	else
		right_height = 1;
	return (left_height > right_height ? left_height : right_height);
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
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

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
	while (current->left != NULL)
	{
		if (binary_tree_balance(current) != -1)
			current = current->left;
		else
			return (0);
	}
	current = tree;
        while (current->right != NULL)
        {
                if (binary_tree_balance(current) != -1)
                        current = current->right;
                else
                        return (0);
        }

	return (1);
}

