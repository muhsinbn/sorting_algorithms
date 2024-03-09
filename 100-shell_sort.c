#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the shell sort algorithm with knuth sequence
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			while ((j >= gap) && (temp < array[j - gap]))
			{
				if (array[j] != array[j - gap])
				{
					array[j] = array[j - gap];
				}
				j -= gap;
			}
			if (array[j] != temp)
				array[j] = temp;
		}
		gap = gap / 3;
		print_array(array, size);
	}
}
