#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: the array of integers
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{
	partition(array, 0, size - 1, size);
}

/**
 * partition - the divide and conquer
 * @array: the list of integers
 * @bot: the first integer
 * @top: the last integer
 * @size: the length of array
 */
void partition(int *array, int bot, int top, size_t size)
{
	if (bot < top)
	{
		int sorted = sorted_array(array, bot, top, size);

		partition(array, bot, sorted - 1, size);
		partition(array, sorted + 1, top, size);
	}
}

/**
 * sorted_array - the divide and conquer
 * @array: the list of integers
 * @bot: the first integer
 * @top: the last integer
 * @size: the length of array
 * Return:- Always 0
 */

int sorted_array(int *array, int bot, int top, size_t size)
{
	int swap, new_pivot;
	int pivot = array[top];
	int k = bot, j = bot;

	for (; j < top; j++)
	{
		if (array[j] <= pivot)
		{
			if (k != j)
			{
				swap = array[k];
				array[k] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
			k++;
		}
	}

	if (pivot != array[k])
	{
	new_pivot = array[k];
	array[k] = array[top];
	array[top] = new_pivot;
	print_array(array, size);
	}

	return (k);
}
