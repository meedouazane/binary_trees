#include "binary_trees.h"
#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: Depth of tree.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: is a pointer to the first node.
 * @second: is a pointer to the second node.
 * Return: a pointer to the lowest common ancestor node, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	       const binary_tree_t *second)
{
	size_t first_depth, second_depth;
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
	{
		ancestor = (binary_tree_t *)first;
		return (ancestor);
	}

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	if (first_depth > second_depth)
	{
		while (first_depth > second_depth)
		{
			first = first->parent;
			first_depth = binary_tree_depth(first);
		}
	}
	else if (first_depth < second_depth)
	{
		while (first_depth < second_depth)
		{
			second = second->parent;
			second_depth = binary_tree_depth(second);
		}
	}
	if (first_depth == second_depth)
	{
		while (first->n != second->n)
		{
			first = first->parent;
			second = second->parent;
		}
		ancestor = (binary_tree_t *)first;
		return (ancestor);
	}
	return (NULL);
}
