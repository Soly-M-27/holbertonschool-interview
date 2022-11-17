#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: pointer on the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t x;
	skiplist_t *n_pos, *n_mid;

	if (!list)
		return (NULL);
	n_pos = list, n_mid = list;
	while (n_pos && n_pos->next && (n_pos->n) < value)
	{
		n_mid = n_pos;
		if (n_pos->express)
		{
			n_pos = n_pos->express;
			printf("Value checked at index [%lu] = [%d]\n", n_pos->index,
				   n_pos->n);
		}
		else
			while (n_pos->next)
				n_pos = n_pos->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", n_mid->index,
	n_pos->index);
	for (x = n_mid->index; x <= (n_pos->index) && (n_mid->n <= value);
		 x++, n_mid = n_mid->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", x, n_mid->n);
		if (n_mid && (n_mid->n) == value)
		{
			return (n_mid);
		}
	}
	if (n_mid)
	{
		printf("Value checked at index [%lu] = [%d]\n", x, n_mid->n);
	}
	return (NULL);
}
