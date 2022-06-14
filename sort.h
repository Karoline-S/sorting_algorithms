#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/* Functions provided in project requirements */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void insertion_sort_back(listint_t **list, listint_t *node);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void quickrec(int *array, int start, int end, size_t size);
void swap(int *x, int *y);
int partition(int *array, size_t start, size_t end, size_t size);
void merge_sort(int *array, size_t size);
void top_down_split_merge(int *copy, int *array, int beginning, int end);
void top_down_merge(int *copy, int *array, int start, int middile, int end);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap_elements(int *min, int *max);
#endif /* _SORT_H */
