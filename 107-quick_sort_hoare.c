#include "sort.h"

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
 *hoarePartition -  performs quicksort algorithm using hoare scheme
 *@array: pointer to an array
 *@size: size of the array
 *@low: starting index
 *@high: ending index
 */
int hoarePartition(int *array, size_t size, int low, int high)
{
	int pivot, above, below;

	pivot = array[high];
	for (above = low - 1, below = high + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(&array[above], &array[below]);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoareRec - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 */
void hoareRec(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoarePartition(array, size, low, high);
		hoareRec(array, size, low, pivot - 1);
		hoareRec(array, size, pivot, high);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers
 *@array: pointer to an array
 *@size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoareRec(array, size, 0, size - 1);
}
