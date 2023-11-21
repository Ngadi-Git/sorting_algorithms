#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * @brief Prints the elements in the specified range of the array.
 *
 * @param array The given array.
 * @param low Lower boundary of the range.
 * @param high Upper boundary of the range.
 */
void print_sequence(int *array, int low, int high)
{
    char *sep = "";

    for (int i = low; i <= high; i++)
    {
        printf("%s%d", sep, array[i]);
        sep = ", ";
    }
    printf("\n");
}

/**
 * @brief Swaps two elements if they are in the specified bitonic direction.
 *
 * @param array The given array.
 * @param e1 Index of the first element.
 * @param e2 Index of the second element.
 * @param dir Direction: 1 for UP and 0 for DOWN.
 */
void swap_dir(int *array, int e1, int e2, int dir)
{
    if (dir == (array[e1] > array[e2]))
    {
        int temp = array[e1];
        array[e1] = array[e2];
        array[e2] = temp;
    }
}

/**
 * @brief Merges two bitonic sequences.
 *
 * @param array The given array.
 * @param low Lower boundary of the range.
 * @param high Upper boundary of the range.
 * @param dir Direction: 1 for UP and 0 for DOWN.
 * @param size Size of the array.
 */
void merge_sequence(int *array, size_t low, size_t high, int dir, size_t size)
{
    if (high - low < 1)
        return;

    size_t middle = (low + high) / 2;
    for (size_t i = low, j = middle + 1; i <= middle; i++, j++)
        swap_dir(array, i, j, dir);

    merge_sequence(array, low, middle, dir, size);
    merge_sequence(array, middle + 1, high, dir, size);
}

/**
 * @brief Recursively creates bitonic sequences and merges them.
 *
 * @param array The given array.
 * @param low Lower boundary of the range.
 * @param high Upper boundary of the range.
 * @param dir Direction: 1 for UP and 0 for DOWN.
 * @param size Size of the array.
 */
void make_sequence(int *array, size_t low, size_t high, int dir, size_t size)
{
    if (high - low < 1)
        return;

    char *direction = (dir == 1) ? "UP" : "DOWN";
    printf("Merging [%ld/%ld] (%s):\n", high - low + 1, size, direction);
    print_sequence(array, low, high);

    size_t middle = (low + high) / 2;
    make_sequence(array, low, middle, 1, size);
    make_sequence(array, middle + 1, high, 0, size);

    merge_sequence(array, low, high, dir, size);
    printf("Result [%ld/%ld] (%s):\n", high - low + 1, size, direction);
    print_sequence(array, low, high);
}

/**
 * @brief Sorts an array of integers in ascending order using the Bitonic sort algorithm.
 *
 * @param array The given array.
 * @param size Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    make_sequence(array, 0, size - 1, 1, size);
}
