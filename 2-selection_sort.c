#include "sort.h"

/**
 * swap_value - swap to values
 *
 * @a: the first value to swap
 * @b: the second value to swap
 */

void swap_value(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: the array of integer
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, b;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		/* searching for the minimum */
		for (b = a + 1; b < size; b++)
			min = (array[b] < *min) ? (array + b) : min;
		if ((array + a) != min)
		{
			swap_value(array + a, min);
			print_array(array, size);
		}
	}
}
