#include "binary_trees.h"

/**
 * binary_tree_insert_right - Write a function that inserts a
 * node as the left-child of another node
 * @parent: pointer to node to insert left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to created node, or NULL if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);

	if (newNode == NULL)
		return (NULL);

	newNode->parent = parent;
	newNode->n = value;

	if (parent->right != NULL)
	{
		newNode->right = parent->right;
		parent->right->parent = newNode;
	}
	parent->right = newNode;

	return (newNode);
}

/**
 * binary_tree_insert_left - Write a function that inserts a
 * node as the left-child of another node
 * @parent: pointer to node to insert left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to created node, or NULL if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);

	if (newNode == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newNode->left = parent->left;
		parent->left->parent = newNode;
	}
	parent->left = newNode;

	return (newNode);
}

/**
 * heap_insert - Function that inserts a value into a Max Binary Heap
 * @root: tree
 * @value: Value to be inserted respecting the Max Heap Order. 
 * 
 * Return: The new heap
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *insert = NULL, *current;

	insert = binary_tree_node(*root, value);
 
    if (root == NULL || *root == NULL)
	{
		*root = insert;
		return (insert);
	}

	if (insert->parent->n < value)
	{
		if (insert->left == NULL)
		{
			insert->left = binary_tree_insert_left(*root, (*root)->n);
			current = insert->parent;
			insert->parent->n = value;
			current->parent = insert->parent;
		}
	}
	if (insert->parent->n > value)
	{
		if (insert->right != NULL)
		{
			if (insert->right->n < value)
			{
				if (insert->left->n > value)
				{
					insert->left->left = binary_tree_insert_left((*root)->left->left, insert->n = value);
				}
			}
		}
		if (insert->right == NULL)
		{
			insert->right = binary_tree_insert_right(*root, insert->n);
		}
		
	}
    return (insert);
}
