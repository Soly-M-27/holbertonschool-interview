#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks is binary tree is an AVL tree
 *
 * @tree: Binary tree root
 * Return: 1 if it is AVL, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int leftNode_H;
	int rightNode_H;

	if (tree == NULL)
	{
		return (0);
	}

	leftNode_H = height(tree->left);
	rightNode_H = height(tree->right);

	if (abs(leftNode_H - rightNode_H) <= 1)
	{
		return (1);
	}

	return (0);
}

/**
 * max - Determins the max height of the left and right
 * subtrees of each node
 * @l: left subtree height value
 * @r: right subtree height value
 * Return: The max hieght value
*/

int max(int l, int r)
{
	return ((l >= r) ? l : r);
}

/**
 * height - Calculates the height of each node and adds them up
 * @node: Node to check if it exists and declare its height
 * Return: 1 if the node has a height, 0 otherwise.
*/

int height(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	return (1 + max(height(node->left), height(node->right)));
}
