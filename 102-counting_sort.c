#include "sort.h"

/**
 * get_max - Gets the max value in an array of ints.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum int in the array.
 */
int get_max(int *array, int size)
{
	int maxi;
	int indx;

	for (maxi = array[0], indx = 1; indx < size; indx++)
	{
		if (array[indx] > maxi)
			maxi = array[indx];
	}

	return (maxi);
}

/**
 * counting_sort - Sorts an array of ints in ascending order
 *                 using the counting sort algorithm.
 * @array: Array of ints.
 * @size: Size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *total, *sorted;
	int  maxi, indx;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxi = get_max(array, size);
	total = malloc(sizeof(int) * (maxi + 1));
	if (total == NULL)
	{
		free(sorted);
		return;
	}

	for (indx = 0; indx < (maxi + 1); indx++)
		total[indx] = 0;
	for (indx = 0; indx < (int)size; indx++)
		total[array[indx]] += 1;
	for (indx = 0; indx < (maxi + 1); indx++)
		total[indx] += total[indx - 1];
	print_array(total, maxi + 1);

	for (indx = 0; indx < (int)size; indx++)
	{
		sorted[total[array[indx]] - 1] = array[indx];
		total[array[indx]] -= 1;
	}

	for (indx = 0; indx < (int)size; indx++)
		array[indx] = sorted[indx];

	free(sorted);
	free(total);
}
