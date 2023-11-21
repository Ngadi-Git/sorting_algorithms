#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to swapped.
 */
void swap_ints(int *a, int *b)
{
	int swp;

	swp = *a;
	*a = *b;
	*b = swp;
}

/**
 * bubble_sort - Sorts array of integers in ascending order.
 * @array: The array of integers to sort.
 * @size: The size/length of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t indx, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (indx = 0; indx < len - 1; indx++)
		{
			if (array[indx] > array[indx + 1])
			{
				swap_ints(array + indx, array + indx + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
