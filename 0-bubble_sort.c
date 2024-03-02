#include "sort.h"

/**
 * swap - function to swap integers
 * @x: first integer
 * @y: second integer
 *
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - Function that sorts an array of integers in ascending order
 * @array: integer array
 * @size: array size
 *
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i;

	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				print_array(array, size);
				swapped = 1;
			}
		}
	} while (swapped);
}
