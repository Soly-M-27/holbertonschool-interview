#include "binary_trees.h"

/**
 * heap_insert - Function that inserts a value into a Max Binary Heap
 * @root: tree
 * @value: Value to be inserted respecting the Max Heap Order. 
 * 
 * Return: The new heap
 */

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *insert = malloc(sizeof(heap_t));

    if (**root == NULL)
        return (NULL);

    if (insert == NULL)
        return (NULL);

    if (*root == NULL)
    {
        insert->parent = *root;
        insert->n = value;
        insert->left = insert->right = NULL;
    }

    if ((*root)->parent->n < value)
    {

        if (insert->left == NULL)
            insert->left = insert->parent;
        else
            insert->right = insert->parent;
        insert->parent = *root;
    }

    if (insert->n > value)
    {
        if (insert->left == NULL)
            insert->left = insert->parent;
        else
            insert->right = insert->parent;
        insert->parent = *root;           
    }



    return (insert);
}
