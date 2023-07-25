#include "sort.h"

/**
 * partition - partitions an array
 * @arr: the array
 * @left: the leftmost index
 * @right: the rightmost index
 * @size: the full array size
 * Return:the pivot index
 */
int partition(int *arr, int left, int right, size_t size)
{
	int i, k, pivot, tmp;

	pivot = arr[right];
	i = left;

	for (k = left; k < right; k++)
	{
		if (arr[k] < pivot)
		{
			if (i != k)
			{
				tmp = arr[k];
				arr[k] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[right])
	{
		tmp = arr[i];
		arr[i] = arr[right];
		arr[right] = tmp;
		print_array(arr, size);
	}

	return (i);
}

/**
 * sorter - recursive sorting algorithm
 * @arr: the array
 * @left: the leftmost index
 * @right: the rightmost index
 * @size: the full size of array
 */
void sorter(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right, size);
		sorter(arr, left, pivot - 1, size);
		sorter(arr, pivot + 1, right, size);
	}
}

/**
 * quick_sort - quicksort algorithm
 * @array: the array to be sorted
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sorter(array, 0, size - 1, size);
}
