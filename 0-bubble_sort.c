#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	int flag;
	int tmp = 0;
	ssize_t i;

	if (size < 2 || array == NULL)
		return;
	while(1)
	{
		flag = 0;

		for (i = 0; i < size -1; i++)
		{
			if array[i] > array[i + 1]
				{
					tmp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tmp;
					print_array(array, size);
					flag = 1;
				}
		}
	}
}
