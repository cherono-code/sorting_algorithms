#include "sort.h"

/**
 * bubble_sort - the function that sorts arrays using
 * bubble sort algorith
 * @array:- the pointer to the array to sort
 * @size:- the size of the array
 * Return:- Always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swap = -1;
	int temp;



	if (size < 2)
		return;

	while (swap != 0)
	{
		swap = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap++;

				print_array(array, size);
			}
		}

	}
}
