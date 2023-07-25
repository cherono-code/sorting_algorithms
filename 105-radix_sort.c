#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum integer in the array
 */
int get_max(int *array, int size)
{
	int max, e;

	for (max = array[0], e = 1; e < size; e++)
	{
		if (array[e] > max)
			max = array[e];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @sig: significant digit to sort on
 * @buff: buffer to store the sorted array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t e;

	for (e = 0; e < size; e++)
		count[(array[e] / sig) % 10] += 1;

	for (e = 0; e < 10; e++)
		count[e] += count[e - 1];

	for (e = size - 1; (int)e >= 0; e--)
	{
		buff[count[(array[e] / sig) % 10] - 1] = array[e];
		count[(array[e] / sig) % 10] -= 1;
	}

	for (e = 0; e < size; e++)
		array[e] = buff[e];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Description: Implements the LSD radix sort algorithm Prints
 * the array after each significant digit increase
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
