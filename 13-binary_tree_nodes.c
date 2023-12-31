#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes with at least one child
 * @tree: root node of the tree to traverse
 * Return: Num of nodes, 0 if tree is NULL
 *
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
		return (0);
	}

	if ((tree->left != NULL) || (tree->right != NULL))
	{
		return (binary_tree_nodes(tree->left) +
				binary_tree_nodes(tree->right) + 1);
	}
	return (0);
}
