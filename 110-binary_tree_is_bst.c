#include <limits.h>
#include "binary_trees.h"
/**
 * max_left_value - find the max value in tree.
 * @tree: is a pointer to the root node of the tree to check
 * Return: max value.
 */
int max_left_value(const binary_tree_t *tree)
{
    if (tree == NULL)
        return INT_MIN;

    int max = tree->n;
    int right_max = max_left_value(tree->right);
    int left_max = max_left_value(tree->left);

    if (right_max > max)
        max = right_max;
    if (left_max > max)
        max = left_max;

    return max;
}

/**
 * low_right_value - find the lowest value in tree.
 * @tree: is a pointer to the root node of the tree to check
 * Return: lowest value.
 */
int low_right_value(const binary_tree_t *tree)
{
    if (tree == NULL)
        return INT_MAX;

    int low = tree->n;
    int right_low = low_right_value(tree->right);
    int left_low = low_right_value(tree->left);

    if (right_low < low)
        low = right_low;
    if (left_low < low)
        low = left_low;

    return low;
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int max_left = max_left_value(tree->left);
    int low_right = low_right_value(tree->right);
    int value = tree->n;

    if (value > max_left && value < low_right)
        return 1;

    return 0;
}

