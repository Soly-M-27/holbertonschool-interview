#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node
 * @parent: Root/Head of Binary Tree
 * @value: Value to be created asa node
 *
 * Return: Pointer to the new node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

    if (newNode == NULL)
        return (NULL);

    newNode->parent = parent;
    newNode->n = value;
    newNode->left = newNode->right = NULL;

    return (newNode);
}
