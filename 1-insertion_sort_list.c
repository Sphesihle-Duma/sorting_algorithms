#include "sort.h"
/**
 * insertion_sort_list - sorts the doubly linked list
 * @list: pointer that points to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = *list;
	listint_t *unsorted = (*list)->next;
	listint_t *current;

	while((*list)->prev)
		*list = (*list)->prev;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (unsorted != NULL)
	{
		current = unsorted;
		unsorted = unsorted->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->prev->next = current->next;
			if (current->prev->prev != NULL)
				current->prev->prev->next = current;
			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;
			if (current->prev == NULL)
				sorted = current;
			else
				current->prev->next = current;
			print_list(sorted);
		}
	}
	*list = sorted;
}

