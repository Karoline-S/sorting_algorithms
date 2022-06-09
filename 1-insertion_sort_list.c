#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list by insertion sort
 * @list: a double pointer to the list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *smaller;

	while (current->next != NULL)
	{
		if (current->next->n < current->n)
		{
			smaller = current->next;
			current->next = smaller->next;
			if (current->next != NULL)
				current->next->prev = current;
			smaller->next = current;
			smaller->prev = current->prev;
			current->prev = smaller;
			if (smaller->prev == NULL)
			{
				*list = current->next;
			}
			current->prev->prev->next = current;
			print_list(*list);
		}
		else
		{
			current = current->next;
		}
	}
}
