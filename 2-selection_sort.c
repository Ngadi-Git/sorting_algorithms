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
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t ith, jth;

	if (array == NULL || size < 2)
		return;

	for (ith = 0; ith < size - 1; ith++)
	{
		min = array + ith;
		for (jth = ith + 1; jth < size; jth++)
			min = (array[jth] < *min) ? (array + jth) : min;

		if ((array + ith) != min)
		{
			swap_ints(array + ith, min);
			print_array(array, size);
		}
	}
}
