#include "sort.h"

/**
 * shell_sort - the sort using knuth shell formula
 * @array: the list of interger
 * @size: the size of array
 * Return:- Always 0
 */

void shell_sort(int *array, size_t size)
{
	size_t j, gap, n = 0, k = 0;
	int insert;

	if (!array || size == 0)
		return;

	while (n < size / 3)
		n = n * 3 + 1;

	while (n > 0)
	{

		for (gap = n; gap < size; gap++)
		{
			insert = array[gap];
			j = gap;

			while (j > n - 1 && array[j - n] >= insert)
			{
				array[j] = array[j - n];
				j = j - n;
			}
			array[j] = insert;
		}
		n = (n - 1) / 3;
		print_array(array, size);
		k++;
	}
}
