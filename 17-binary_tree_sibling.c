#include "binary_trees.h"
/*
 * binary_tree_sibling - finds the sibling of a node.
 * @node: is a pointer to the node to find the sibling
 * Return: a pointer to the sibling node or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
		       node->parent->parent == NULL)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
