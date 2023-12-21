#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the list.
 * @a: The first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	if (b->next != NULL)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (b->prev == NULL)
		*list = b;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: A pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tracknode = NULL;
	listint_t *last = NULL;
	listint_t *placeholder = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tracknode = (*list)->next;

	while (tracknode != NULL)
	{
		placeholder = tracknode->next;
		last = tracknode->prev;

		while (last != NULL && tracknode->n < last->n)
		{
			swap_nodes(list, last, tracknode);
			last = tracknode->prev;
		}

		tracknode = placeholder;
	}
}
