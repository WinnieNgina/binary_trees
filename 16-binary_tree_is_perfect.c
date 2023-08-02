#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height_perf - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0 or max height
 */
size_t binary_tree_height_perf(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height_perf(tree->left);
	right_height = binary_tree_height_perf(tree->right);

	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}
/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, return 0 or return 1 if true
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	/*check if that tree is empty*/
	if (tree == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height_perf(tree->left);
	right_height = binary_tree_height_perf(tree->right);

	/*check if height on left and right are equal*/
	if (left_height != right_height)
	{
		return (0);
	}

	/*check if inner nodes have a child each*/
	if (tree->left != NULL && tree->right != NULL)
	{
		return (1);
	}
		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}

