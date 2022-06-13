#include "sort.h"
/**
* quick_sort - sorts an array using the quick sort algorithm
*
* @array: pointer to integer array
* @size: size of integer array
*
* Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickrec(array, 0, size - 1, size);
}
/**
* quickrec - recursive function for sorting array
*
* @array: pointer to integer array
* @start: starting index
* @end: ending index
* @size: size of the array
*
* Return: Nothing
*/
void quickrec(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quickrec(array, start, pivot - 1, size);
		quickrec(array, pivot + 1, end, size);
    /** quicksorting each partition*/
	}
}
/**
  * swap- swaps values
  *@x: value to swap
  *@y: second value to swap
*/
void swap(int *x, int *y)
{
  int tmp = 0;
  tmp = *x;
  *x = *y;
  *y = tmp;
}
/**
* partition - partitions array, swaps values, and prints
*
* @array: pointer to integer array
* @start: starting index
* @end: ending index
* @size: size of the array
*
* Return: Nothing
*/
int partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i = start - 1;
	size_t j;
	size_t place = 0;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
      /** if j index is greater than last index*/
		{
			i++;
			swap(&array[i], &array[j]);

			if (array[j] != array[i])
				print_array(array, size);
		}
	}
	i++;
	place = i;
	swap(&array[i], &array[end]);
	if (array[j] != array[i])
		print_array(array, size);
	return (place);
  /** Returns a partitioned array with lower and higher numbers split */
}
