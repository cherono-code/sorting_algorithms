#include "sort.h"

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
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, e;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (e = 0; e < (max + 1); e++)
		count[e] = 0;
	for (e = 0; e < (int)size; e++)
		count[array[e]] += 1;
	for (e = 0; e < (max + 1); e++)
		count[e] += count[e - 1];
	print_array(count, max + 1);

	for (e = 0; e < (int)size; e++)
	{
		sorted[count[array[e]] - 1] = array[e];
		count[array[e]] -= 1;
	}

	for (e = 0; e < (int)size; e++)
		array[e] = sorted[e];

	free(sorted);
	free(count);
}
