#include "sort.h"

/**
 * swap - Swaps positions of values in an array.
 * @array: Array to be modified.
 * @first: Index of the first element.
 * @second: Index of the second element.
 *
 * Return: Nothing.
 */
void swap(int *array, int first, int second)
{
	int holder;

	holder = array[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * build_max_heap - Builds a max heap from an array.
 * @array: Array to be converted to a heap.
 * @end_index: End index as the array is partitioned.
 * @start_index: Starting index as the array is sorted.
 * @array_size: Original size of the array.
 *
 * Return: Nothing.
 */
void build_max_heap(int *array, int end_index, int start_index, int array_size)
{
	int largest, left, right;

	largest = start_index;
	left = (start_index * 2) + 1;
	right = (start_index * 2) + 2;

	if (left < end_index && array[left] > array[largest])
		largest = left;

	if (right < end_index && array[right] > array[largest])
		largest = right;

	if (largest != start_index)
	{
		swap(array, start_index, largest);
		print_array(array, array_size);
		build_max_heap(array, end_index, largest, array_size);
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	int start_index, i;

	if (!array || size < 2)
		return;

	start_index = ((int)size - 1) / 2;

	/* Build max heap */
	for (i = start_index; i >= 0; i--)
	{
		build_max_heap(array, size, i, size);
	}

	/* Destroy max heap and print the sorted array */
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		build_max_heap(array, i, 0, size);
	}
}
