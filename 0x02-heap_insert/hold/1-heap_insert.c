#include "binary_trees.h"

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
    binary_tree_t *insert = NULL;

    if (*root == NULL || root == NULL)
    {
        insert = binary_tree_node(*root, value);
        *root = insert;
        return (insert);
    }

    insert = binary_tree_node(*root, value);

    if (insert->parent->n < value)
    {
        if (insert->left == NULL)
            insert->left = binary_tree_node(insert->parent, value);
        else
            insert->right = binary_tree_node(insert->parent, value);
        insert->parent->n = value;
    }

   /* if (insert->parent->n > value)
    {
        if (insert->left == NULL)
            insert->left = binary_tree_node(insert->parent, value);
        else
            insert->right = binary_tree_node(insert->parent, value);
        insert->parent->n = value;           
    }

    return (insert);
}