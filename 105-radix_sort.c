#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - sorts an array by sorting into buckets by focusing on each
 * significant number in LSD order
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, sigdigit, divisor, pass;
	int i, j, k;
	int bucketCount[10];
	int buckets[10][10];

	if (array == NULL || size < 2)
		return;

	max = find_max_elements(array, size);
	divisor = 1;

	for (pass = 0; pass < max; pass++)
	{
		for (i = 0; i < 10; i++)
		{
			bucketCount[i] = 0;
		}

		for (i = 0; i < (int)size; i++)
		{
			sigdigit = (array[i] / divisor) % 10;
			buckets[sigdigit][bucketCount[sigdigit]] = array[i];
			bucketCount[sigdigit] += 1;
		}

		i = 0;

		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucketCount[k]; j++)
			{
				array[i] = buckets[k][j];
				i++;
			}
		}

		divisor *= 10;
		print_array(array, size);
	}
}

/**
 * find_max_elements - counts the number of digits in each number in
 * in an array to find the maximum number of digits
 * @array: the array to be checked
 * @size: the size of the array
 *
 * Return: number of digits in largest number as int
 */
int find_max_elements(int *array, size_t size)
{
	int idx, count, num;
	int max = 0;

	for (idx = 0; idx < (int)size; idx++)
	{
		num = array[idx];

		for (count = 0; num != 0; count++)
			num = num / 10;

		if (count > max)
			max = count;
	}

	return (max);
}
