#include "sort.h"

/**
 * swap - swap the nodes
 * @list: the list head
 * @node1: first node
 * @node2: second node
 * Return: false
 */
void swap(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts the doubly linked list using cocktail algor
 * @list: the head of the list
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list, *end = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap(list, start, start->next);
				print_list(*list);
				swapped = 1;
			} else
				start = start->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		end = start;
		start = *list;

		while (start->next != end)
			start = start->next;
		while (start->prev != NULL && start->prev->n > start->n)
		{
			swap(list, start->prev, start);
			print_list(*list);
			swapped = 1;
		}
	}
}
