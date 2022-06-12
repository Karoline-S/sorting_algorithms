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

	/* allocate space for a copy of array */
	arrCopy = malloc(sizeof(*array) * size);
	if (arrCopy == NULL)
		return;

	/* copy array into arrCopy allocated space */
	for (i = 0; i < (int)size; i++)
		copy[i] = array[i];

	/* sort data from arrCopy into array */
	top_down_split_merge(arrCopy, array, 0, end);
}

/**
 * top_down_split_merge - splits array into runs, sorts both runs into arrCopy
 * and merges them back into array
 * @arrCopy: a space allocated to receive the copy
 * @array: the orray to be copied
 * @start: the first element
 * @end: size of the array, or last index + 1
 *
 * Return: nothing
 */
void top_down_split_merge(int *copy, int *array, size_t size, int beginning)
{
	int i;

}



int main(void)
{
	int array [] = {5, 6, 7, 8, 9, 10};
	size_t size = 6;

	merge_sort(array, size);
}
