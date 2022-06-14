#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - 
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int end = (int)size - 1;
	int lastIdx, i, maxElements;
	int *arrCopy = NULL;

	if (array == NULL || size < 2)
		return;

	maxElements = find_max_elements(array, size);

	arrCopy = malloc(sizeof(*array) * size);
	if (arrCopy == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		arrCopy[i] = array[i];

	lastIdx = end;

	while (end >= 0)
	{
		end = lastIdx;
		
		end--;
	}
}

/**
 * find_max_elements - counts the number of digits in each number in
 * in an array to find the maximum number of digits
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: nothing
 */
int find_max_elements(int *array, size_t, size)
{
	int idx = 0;
	int num = 0;
	int count = 0;
	int max = 0;

	while (idx < (int)size)
	{
		num = array[idx];
		do
		{
			num /= 10;
			count++;
		} while (num != 0);

		if (count > max)
			max = count;

		idx++;
	}

	printf("max = %d\n", max);

	return (max);
}
