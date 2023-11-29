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
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: is a pointer to the root node of the tree.
 * Return: Number of the nodes with at least 1 child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		nodes++;
	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);
	return (nodes);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is perferct otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_nodes(tree->left);
	right = binary_tree_nodes(tree->right);
	if (left == right)
		return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));
	return (0);
}
