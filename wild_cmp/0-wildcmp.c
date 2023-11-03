#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * wildcmp - Function that compares two strings and
 * returns 1 if the string can be considered identical,
 * otherwise return 0
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if they match, 0 if not
*/

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)))
		{
			return (1);
		}
	}

	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
