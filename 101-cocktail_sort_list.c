#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - swap nodes
 * @node1: node 1, node 1 and 2 are two adjacent nodes
 * @node2: node 2, node 1 and 2 are two adjacent nodes
 * Return: void
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - use cocktail sort algorthm to sort double linked list
 * @list: a pointer pointed to the double linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *currentNode = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	currentNode = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (currentNode->next != NULL)
		{
			if (currentNode->n > currentNode->next->n)
			{
				swap_nodes(currentNode, currentNode->next);
				if (currentNode->prev->prev == NULL)
					*list = currentNode->prev;
				print_list(*list);
				swapped = 1;
			}
			else
				currentNode = currentNode->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (currentNode->prev != NULL)
		{
			if (currentNode->n < currentNode->prev->n)
			{
				swap_nodes(currentNode->prev, currentNode);
				if (currentNode->prev == NULL)
					*list = currentNode;
				print_list(*list);
				swapped = 1;
			}
			else
				currentNode = currentNode->prev;
		}
	}
}
