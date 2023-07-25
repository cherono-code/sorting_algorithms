#include "sort.h"
/**
 * selection_sort - the sort by find the smallest and place at begin
 * @array: the array to sort
 * @size: the size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t k = 0, j, min, tmp;

	if (array == NULL || size < 2)
		return;

	for (; k < size - 1; k++)
	{
		min = k;
		for (j = k + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != k)
		{
			tmp = array[k];
			array[k] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
