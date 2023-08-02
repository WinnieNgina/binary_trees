#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_depth_perf - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0 or max height
 */
size_t binary_tree_depth_perf(const binary_tree_t *tree)
{
	size_t left_depth;
	size_t right_depth;

	if (tree == NULL)
	{
		return (0);
	}
	left_depth = binary_tree_depth_perf(tree->left);
	right_depth = binary_tree_depth_perf(tree->right);

	if (left_depth > right_depth)
	{
		return (left_depth + 1);
	}
	else
	{
		return (right_depth + 1);
	}
}
/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0 or return 1 if true
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_depth;
	size_t right_depth;

	/*check if that tree is empty*/
	if (tree == NULL)
	{
		return (0);
	}
	left_depth = binary_tree_depth_perf(tree->left);
	right_depth = binary_tree_depth_perf(tree->right);

	/*check if height on left and right are equal*/
	if (left_depth != right_depth)
	{
		return (0);
	}

	/*check if inner nodes have a child each*/
	if (tree->left != NULL && tree->right != NULL)
	{
		return (1);
	}
		return (0);
	}
