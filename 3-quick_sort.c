#include "sort.h"
#include "2-selection_sort.c"

/**
 * lomuto_partition - Order subset according to the last element as pivot
 *
 * @array: the array of integer
 * @size: the size of the array
 * @left: the starting index of the subset
 * @right: the ending index of the subset
 *
 * Return: the final partition index
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, greater, lower;

	/* Define pivot as last element of sub-array */
	pivot = array + right;
	for (greater = lower = left; lower < right; lower++)
	{
		if (array[lower] < *pivot)
		{
			if (greater < lower)
			{
				swap_value(array + lower, array + greater);
				print_array(array, size);
			}
			greater++;
		}
	}
	if (array[greater] > *pivot)
	{
		swap_value(array + greater, pivot);
		print_array(array, size);
	}
	return (greater);
}

/**
 * lomuto_sort - Use the Lomuto partition scheme
 *
 * @array: the array of integer
 * @size: the size of the array
 * @left: the starting index of the array
 * @right: the ending index of the array
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		/* get index of pivot */
		part = lomuto_partition(array, size, left, right);
		/* sort array part before pivot */
		lomuto_sort(array, size, left, part - 1);
		/* sort array part after pivot */
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array of integer
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
