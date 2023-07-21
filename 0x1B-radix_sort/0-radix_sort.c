#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int getMax(int arr[], size_t n) 
{

	int max = arr[0];

	for (size_t i = 1; i < n; i++) 
	{
		if (arr[i] > max) 
		{
			max = arr[i];
		}
	}
	return (max);
}

void radix_sort(int *array, size_t size) 
{
	int max = getMax(array, size);
	int exp;
	
	for (exp = 1; max / exp > 0; exp *= 10) 
	{
		int *output = malloc(size * sizeof(int));
		int count[10] = {0};

		for (size_t i = 0; i < size; i++) 
			count[(array[i] / exp) % 10]++;

		for (int i = 1; i < 10; i++) 
			count[i] += count[i - 1];

		for (int i = size - 1; i >= 0; i--) 
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			count[(array[i] / exp) % 10]--;
		}

		for (size_t i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
		free(output);
	}
}
