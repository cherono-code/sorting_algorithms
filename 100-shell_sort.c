#include "sort.h"

/**
 * shell_sort - the function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the
 * knuth sequence.
 * @array: the list of integers
 * @size: the length of the array.
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t interval, inner, outer;
	int tempp;

	if (!array || size < 2)
		return;

	interval = 1;
	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			tempp = array[outer];
			inner = outer;

			while (inner > interval - 1 && array[inner - interval] >= tempp)
			{
				array[inner] = array[inner - interval];
				inner = inner - interval;
			}
			array[inner] = tempp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
