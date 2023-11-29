#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: is a pointer to the root node of the tree to measure
 * Return: the balance
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_left = 0;
	int balance_right = 0;
	int balance = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if (tree->left != NULL)
		balance_left = 1;
	else
		balance_left = -2;
	if (tree->right != NULL)
		balance_right = 1;
	else
		balance_right = -2;
	balance = balance_left + balance_right;
	return (balance);
}
