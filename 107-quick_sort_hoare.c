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
	int pivot = array[high];
	int h, l;

	for (l = low - 1; h = high + 1; l < h)
	{
		do {
			l++;
		} while (array[l] < pivot);
		do {
			h--;
		} while (array[h] > pivot);

		if (l < h)
		{
			swap(&array[l], &array[h]);
			print_array(array, size);
		}
		return (l);
	}
}
/**
 * hoareRec - recursively sorts an array
 *@array: pointer to an array
 *@size: size of the array
 *@low: starting index of the partition
 *@high: ending index of the partition
 */

void hoareRec(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoarePartition(array, low, high, size);
		hoareRec(array, size, low, pivot -1);
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
	hoareRec(array, size, 0, size -1);
}
