#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: an array of integer
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b, c;
	int temp;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = temp;
				for (c = 0; c < size; c++)
				{
					printf("%d", array[c]);
					if (c < size - 1)
						printf(", ");
				}
				printf("\n");
			}
		}
	}
}
