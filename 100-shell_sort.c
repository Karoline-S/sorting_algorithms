#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort algo and Knuth sequence
 * @array: a pointer to the array
 * @size: the size of the array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int out, in, hold;

	while (gap <= (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (out = gap; out < (int)size; out++)
		{
			hold = array[out];
			for (in = out - gap; in >= 0 && hold < array[in];
			     in -= gap)
				array[in + gap] = array[in];
			array[in + gap] = hold;
		}
		print_array(array, size);
		gap /= 3;
	}
}
