#include <stdlib.h>
#include "sort.h"

/**
 * swap_elements - swap two elements in an array
 * @min: small element
 * @max: big element
 * Return: void
 */
void swap_elements(int *min, int *max)
{
	int temp;

	temp = *min;
	*min = *max;
	*max = temp;
}
/**
 * selection_sort - sorts an integers array in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_index;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (i != min_index)
		{
			swap_elements(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
