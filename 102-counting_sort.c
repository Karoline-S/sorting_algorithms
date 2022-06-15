#include "sort.h"
#include <string.h>
#include <stdlib.h>
/**
 * counting_sort -Sorts an array of integers
 * in ascending order using the
 * Counting sort algorithm
 * @array: the array to sort
 * @size: size of the array
 * Return: no return
 */
void counting_sort(int *array, size_t size)
{
	int n, i;
	int *buff, *a;

	if (size < 2)
		return;
	for (n = i = 0; i < (int)size; i++)
		if (array[i] > n)
			n = array[i];
	buff = malloc(sizeof(int) * (n + 1));
	if (buff == NULL)
		return;
	for (i = 0; i <= n; i++)
		buff[i] = 0;
	for (i = 0; i < (int)size; i++)
		buff[array[i]] += 1;
	for (i = 1; i <= n; i++)
		buff[i] += buff[i - 1];
	print_array(buff, (n + 1));
	a = malloc(sizeof(int) * (size + 1));
	if (a == NULL)
	{
		free(buff);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		a[buff[array[i]] - 1] = array[i];
		buff[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = a[i];
	free(buff);
	free(a);
}
