#include "sort.h"

/**
 * initialize_array - Initializes array elements to zero.
 * @array: Array to be initialized.
 * @size: Size of the array.
 */
void initialize_array(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        array[i] = 0;
}

/**
 * get_max_value - Gets the maximum value in the array.
 * @array: Array to get the max value from.
 * @size: Size of the array.
 * 
 * Returns: The maximum value in the array.
 */
int get_max_value(const int *array, size_t size)
{
    int max = array[0];

    for (size_t i = 1; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Performs counting sort for LSD radix sort.
 * @array: Initial array.
 * @size: Size of the array.
 * @place: Position of the LSD (least significant digit).
 */
void counting_sort(int *array, size_t size, int place)
{
    const int base = 10;

    int *position = malloc(sizeof(int) * base);
    if (!position)
        return;

    initialize_array(position, base);

    for (size_t i = 0; i < size; i++)
        position[(array[i] / place) % base] += 1;

    for (int i = 1; i < base; i++)
        position[i] += position[i - 1];

    int *sorted = malloc(sizeof(int) * size);
    if (!sorted)
    {
        free(position);
        return;
    }

    for (int k = size - 1; k >= 0; k--)
    {
        position[(array[k] / place) % base] -= 1;
        sorted[position[(array[k] / place) % base]] = array[k];
    }

    free(position);

    for (size_t i = 0; i < size; i++)
        array[i] = sorted[i];

    free(sorted);
}

/**
 * radix_sort - Performs the LSD (least significant digit) radix sort.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void radix_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int max_value = get_max_value(array, size);
    int place = 1;

    while (max_value / place > 0)
    {
        counting_sort(array, size, place);
        print_array(array, size);
        place *= 10;
    }
}
