#include "sort.h"

<<<<<<< HEAD
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
=======
/**
 * arr_zero_init - initialize array by 0
 * @quadr $ lennon
 * @array: array to be initialized
 * @size: size of the array
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_max - gets the maximum value in the array
 * @array: array to get max value from
 * @size: size of the array
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];	/* start from first index */

	for (i = 1; i < size; i++)
	{
		if (max < array[i])
>>>>>>> ac057a915efdf8de594253836f0df3c8803a9d6c
			max = array[i];
	}

	return (max);
}

/**
<<<<<<< HEAD
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
=======
 * sort_counter - sorts an array using the counting_sort
 * algorithm for LSD radix sort algorithm
 * @array: initial array
 * @size: size of the array
 * @place: position of the LSD (least significant digit)
 */
void sort_counter(int *array, size_t size, int place)
{
	int k, *position, *sumPosition, *sorted;
	size_t i, j;

	position = malloc(sizeof(int) * 10);
	if (!position)
		return;
	arr_zero_init(position, 10);

	for (i = 0; i < size; i++)
		position[(array[i] / place) % 10] += 1;    /* position at LSD */

	sumPosition = malloc(sizeof(int) * 10);
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, 10);
	sumPosition[0] = position[0];   /* make first index equal */

	for (j = 1; j < 10; j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (k = size - 1; k >= 0; k--)  /* get the sorted array */
	{
		sumPosition[(array[k] / place) % 10] -= 1;
		sorted[sumPosition[(array[k] / place) % 10]] = array[k];
	}
	free(sumPosition);

	for (i = 0; i < size; i++)  /* update array */
		array[i] = sorted[i];
	free(sorted);
}

/**
 * radix_sort - peforms the the LSD (least significant Digit)
 * radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, position = 1;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	while ((max / position) > 0)
	{
		sort_counter(array, size, position);
		print_array(array, size);
		position *= 10;
	}
>>>>>>> ac057a915efdf8de594253836f0df3c8803a9d6c
}
