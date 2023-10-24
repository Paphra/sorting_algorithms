#include "sort.h"

/**
 * insertion_sort_list - implement the insertion sort for doubly linked list
 * @list: the pointer to the first node
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *iter;

	if (!list || !*list)
		return;

	current = (*list)->next;
	while (current)
	{
		iter = current;
		current = current->next;

		while (iter->prev && iter->prev->n > iter->n)
		{
			tmp = iter->prev;
			if (tmp->prev)
				tmp->prev->next = iter;
			else
				*list = iter;
			if (iter->next)
				iter->next->prev = tmp;
			iter->prev = tmp->prev;
			tmp->next = iter->next;
			iter->next = tmp;
			tmp->prev = iter;

			print_list(*list);
		}
	}
}
