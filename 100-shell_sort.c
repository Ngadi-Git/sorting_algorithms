#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, ith, jth;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (ith = gap; ith < size; ith++)
		{
			jth = ith;
			while (jth >= gap && array[jth - gap] > array[jth])
			{
				swap_ints(array + jth, array + (jth - gap));
				jth -= gap;
			}
		}
		print_array(array, size);
	}
}
