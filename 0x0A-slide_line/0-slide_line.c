#include "slide_line.h"

/**
 * slide_line - Given an array of integers, we want to be able to 
 * slide & merge it to the left or to the right. Identical numbers, 
 * if they are continuous or separated by zeros, should be merged.
 *
 * @line: pointer to array of ints
 * @size: the size of the array of ints
 * @dir: defined int by macro to determine if to slide left or right.
 * if direction is not left or right, return 0 and program fails.
 *
 * Return: 1 if successful and 0 if not.
 */

int slide_line(int *line, size_t size, int dir)
{
	int index = 0, placeholder = 0;

	if (size < 1 || (dir != SLIDE_RIGHT && dir != SLIDE_LEFT))
		return (0);

	if (dir == SLIDE_LEFT)
	{
		for (index = 1; index < (int)size; index++)
		{
			if (line[index] == line[placeholder] && line[index])
				slide(line, index, placeholder++);
			else if (line[index] != line[placeholder] && line[index])
			{
				if (line[placeholder] != 0)
					placeholder++;
				if (line[placeholder] == 0)
					slide(line, index, placeholder);
			}
		}
	}
	else if (dir == SLIDE_RIGHT)
	{
		placeholder = (size - 1);
		for (index = (size - 2); index >= 0; index--)
		{
			if (line[index] == line[placeholder] && line[index])
				slide(line, index, placeholder--);
			else if (line[index] != line[placeholder] && line[index])
			{
				if (line[placeholder] != 0)
					placeholder--;
				if (line[placeholder] == 0)
					slide(line, index, placeholder);
			}
		}
	}
	
	return (1);
}

/**
 * slide - adds the value of the index to the placeholder and
 * resets the value at index to 0
 *
 * @line: pointer to the array of ints to slide and merge
 * @idx: catch value that needs to be shifted
 * @placeholder: index to merge index's value into
 */

void slide(int *line, int idx, int placeholder)
{
	line[placeholder] += line[idx];
	line[idx] = 0;
}