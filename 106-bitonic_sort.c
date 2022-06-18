#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * bitonic sort - sorts array of ints in ascending order with
 * bitonic sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: nothing
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1;

	if (array == NULL || size < 2)
		return;

	recursive_sort(array, 0, size, up);
}

/**
 * recursive_sort - sorting into a bitonic sequence
 * @array: the array to be sorted into bitonic sequence
 * @start: the starting point for the sequence
 * @seqSize: size reducing with each call
 * @dir: indicator for sorting up or down
 * Return: nothing
 */
void recursive_sort(int *array, int start, int seqSize, int dir)
{
	int k, i;

	if (seqSize > 1)
	{
		k = seqSize / 2;
		printf("Merging [%d/16] (UP):\n", seqSize);
		for (i = start; i < k; i++)
		{
			printf("%d, ", array[i]);
		}
		printf("\n");
		recursive_sort(array, start, k, 1);
		printf("Merging [%d/16] (DOWN)\n", seqSize);
		recursive_sort(array, start + k, k, 0);
		sequence_merge(array, start, seqSize, dir);
	}
}

/**
 * sequence_merge - 
 * @array: the array to be merged as sorted
 * @start: staring point for merge
 * @seqSize: size of run
 * @dir: indicator for sort up or down
 * Return: nothing
 */
void sequence_merge(int *array, int start, int seqSize, int dir)
{
	int k, i, temp;

	if (seqSize > 1)
	{
		k = seqSize / 2;

		for (i = start; i < start + k; i++)
		{
			if (dir == (array[i] > array[i + k]))
			{
				temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}
		}

		sequence_merge(array, start, k, dir);
		sequence_merge(array, start + k, k, dir);
	}
}
