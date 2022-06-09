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
				*list = smaller;
			else
				smaller->prev->next = smaller;

			print_list(*list);
			sort_back(list, smaller);
		}
		else
		{
			current = current->next;
		}
	}
}

/**
 *
 *
 *
 *
 */
void sort_back(listint_t **list, listint_t *node)
{
	listint_t *larger;

	if (*list == node)
		return;

	if (node->n >= node->prev->n)
		return;

	larger = node->prev;
	larger->next = node->next;

	if (larger->next != NULL)
		larger->next->prev = larger;

	node->next = larger;
	node->prev = larger->prev;
	larger->prev = node;

	if (node->prev == NULL)
		*list = node;
	else
		node->prev->next = node;

	print_list(*list);
	sort_back(list, node);
}
