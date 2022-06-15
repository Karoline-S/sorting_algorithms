#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_sort - sorts an array of ints in assecending order using
 * merge sort, top-down
 * @array: a pointer to the array
 * @size: the size of the array
 *
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	int *arrCopy;
	int i;
	int end = (int)size;

	if (array == NULL || size < 2)
		return;

	arrCopy = malloc(sizeof(*array) * size);
	if (arrCopy == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		arrCopy[i] = array[i];

	top_down_split_merge(arrCopy, array, 0, end);

	free(arrCopy);
}

/**
 * top_down_split_merge - splits array into runs, sorts both runs into arrCopy
 * and merges them back into array
 * @copy: a space allocated to receive the copy
 * @array: the orray to be copied
 * @beginning: the first element
 * @end: size of the array, or last index + 1
 *
 * Return: nothing
 */
void top_down_split_merge(int *copy, int *array, int beginning, int end)
{
	int mid;

	if (end - beginning <= 1)
		return;

	mid = (end + beginning) / 2;

	top_down_split_merge(array, copy, beginning, mid);
	top_down_split_merge(array, copy, mid, end);
	top_down_merge(array, copy, beginning, mid, end);
}

/**
 * top_down_merge - merges smaller runs from larger array
 * @copy: a copy of the array to sort
 * @array: orginal array to replace values in sorted order
 * @start: starting point of a left side run
 * @mid: end point (with - 1) of a left side run, starting point of a right
 * side run
 * @end: ending point (-1) of a right side run
 *
 * Return: nothing
 */
void top_down_merge(int *copy, int *array, int start, int mid, int end)
{
	int i, j, k, n, m;

	i = n = start;
	j = m = mid;

	printf("Merging...\n[left]: %d", array[n]);

	for (n += 1; n < mid; n++)
		printf(", %d", array[n]);

	printf("\n[right]: %d", array[m]);

	for (m += 1; m < end; m++)
		printf(", %d", array[m]);

	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i++;
		}
		else
		{
			copy[k] = array[j];
			j++;
		}
	}

	k = start;

	printf("\n[Done]: %d", copy[k]);

	for (k = start + 1; k < end; k++)
		printf(", %d", copy[k]);

	printf("\n");
}
