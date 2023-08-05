#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor(LCA) of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: a pointer to the LCA node of the two given nodes else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent;
	binary_tree_t *second_parent;

	if ((first == NULL) || (second == NULL))
	/*check if nodes are present*/
	{
		return (NULL);
	}
	if (first == second)
	/*check if its the same node*/
	{
		return ((binary_tree_t *)first); /*node is always an ancestor of itself*/
	}
	/*Find parents of both the first node and second node*/
	first_parent = first->parent;
	second_parent = second->parent;
	if ((first == second_parent) || (first_parent == NULL) ||
			(first_parent->parent == NULL && second_parent != NULL))
	/**
	 * check if first node is the parent of the second node
	 * check if the parent of the first node is null(root of the tree)
	 * check if the first node has a grand parent and
	 * if the second has a parent therefore it can't be the root
	 */
	{
		return (binary_trees_ancestor(first, second_parent));
	}
	else if ((second == first_parent) || (second_parent == NULL) ||
			((second_parent->parent == NULL) && (first_parent != NULL)))
	{
		return (binary_trees_ancestor(first_parent, second));
	}
	else
		return (binary_trees_ancestor(first_parent, second_parent));
}
