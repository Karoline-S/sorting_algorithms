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
	int outer, inner, insert;

	while (gap <= (int)size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		outer = gap;

		while (outer < (int)size)
		{
			insert = array[outer];
			inner = outer;

			while (inner > gap - 1 && array[inner - gap] >= insert)
			{
				array[inner] = array[inner - gap];
				inner -= gap;
			}

			array[inner] = insert;
			outer++;
		}

		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
