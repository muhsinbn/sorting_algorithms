#include "sort.h"

void counting_sort(int *array, size_t size);

/**
 * counting_sort - sorts an array of integers in ascending order using
 * couting sort
 * @array: The array to be sorted
 * @size: The size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *counting, *sorted;
	size_t x, y, max = 0;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size; x++)
	{
		if ((size_t)array[x] > max)
			max = (size_t)array[x];
	}
	max++;

	counting = malloc(max * sizeof(int));
	if (counting == NULL)
		return;

	for (x = 0; x < max; x++)
		counting[x] = 0;

	for (x = 0; x < size; x++)
		counting[array[x]]++;

	for (x = 1; x < max; x++)
		counting[x] += counting[x - 1];

	sorted = malloc(size * sizeof(int));
	if (sorted == NULL)
	{
		free(counting);
		return;
	}

	for (y = size - 1; y < size; y--)
	{
		sorted[counting[array[y]] - 1] = array[y];
		counting[array[y]]--;
	}
	for (x = 0; x < size; x++)
		array[x] = sorted[x];

	print_array(array, size);


	free(counting);
	free(sorted);
}
