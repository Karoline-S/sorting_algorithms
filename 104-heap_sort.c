#include "sort.h"

/**
 * swap - swap two elements in an array
 * @a: a pointer to element a
 * @b: a pointer to element b
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - convert the array to a max heap
 * @array: array to be converted
 * @size: size of the array
 * @root: root index of the array
 * @heapSize: the heap size
 * Return: void
 */
void heapify(int array[], int size, int root, int heapSize)
{
	int max, left, right;

	max = root;
	left = 2 * root + 1;
	right = 2 * root + 2;
	if (left < heapSize && array[left] > array[max])
		max = left;
	if (right < heapSize && array[right] > array[max])
		max = right;
	if (max != root)
	{
		swap(&array[root], &array[max]);
		print_array(array, size);
		heapify(array, size, max, heapSize);
	}
}

/**
 * heap_sort - use heap sort to sort an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
