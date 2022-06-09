#include <stdio.h>
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
	listint_t *current = (*list)->next;
	listint_t *hold;

	while (current != NULL)
	{
		if (current->n < current->prev->n)
		{
			hold = current->next;
			sort_back(list, current);
			current = hold;
		}
		else
		{
			current = current->next;
		}
	}
}

/**
 * sort_back - recursively moves a node into position in a doubly linked list
 * @list: a double pointer to the start of the list
 * @node: the node to be sorted
 *
 * Description: checks if the int in @node is lesser than the int in the
 * preceding node and swaps the two if it is. Continues to check the same node
 * until it reaches the start of the list or the int is greater than the int in
 * the preceding node
 * Return: nothing
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
