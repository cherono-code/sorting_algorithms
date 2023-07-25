#include "sort.h"

/**
 * forward_swap - Function to swap the values and sort them for
 * the forward pass.
 * @list: the head of the linked list.
 * @end: the pointer to the tail of the list
 * @start: the pointer to iterate back and forth the list.
 * Return: nothing
 */
void forward_swap(listint_t **list, listint_t **end, listint_t **start)
{
	listint_t *tempp;

	tempp = (*start)->next;
	if ((*start)->prev != NULL)
		(*start)->prev->next = tempp;
	else
		*list = tempp;
	tempp->prev = (*start)->prev;
	(*start)->next = tempp->next;
	if (tempp->next != NULL)
		tempp->next->prev = *start;
	else
		*end = *start;
	(*start)->prev = tempp;
	tempp->next = *start;
	*start = tempp;
}

/**
 * backward_swap - Function to swap values and sort them for the
 * backward pass.
 * @list: the head to the linked list.
 * @end: the pointer to the tail of the list.
 * @start: the pointer to iterate back and forth the list.
 * Return: nothing
 */
void backward_swap(listint_t **list, listint_t **end, listint_t **start)
{
	listint_t *temp;

	tempp = (*start)->prev;
	if ((*start)->next != NULL)
		(*start)->next->prev = tempp;
	else
		*end = tempp;
	tempp->next = (*start)->next;
	(*start)->prev = tempp->prev;
	if (tempp->prev != NULL)
		tempp->prev->next = *start;
	else
		*list = *start;
	(*start)->next = tempp;
	tempp->prev = *start;
	*start = tempp;
}

/**
 * cocktail_sort_list - Function that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shaker sort
 * algorithm.
 * @list: the list of integers.
 * Return: nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int sort = 1;

	if (!*list || !list || !(*list)->next)
		return;

	for (end = *list; end->next != NULL;)
		end = end->next;

	while (sort == 1)
	{
		sort = 0;
		start = *list;

		while (start != end)
		{
			if (start->n > start->next->n)
			{
				forward_swap(list, &end, &start);
				print_list((const listint_t *)*list);
				sort = 1;
			}
			start = start->next;
		}

		start = start->prev;
		while (start != *list)
		{
			if (start->n < start->prev->n)
			{
				backward_swap(list, &end, &start);
				print_list((const listint_t *)*list);
				sort = 1;
			}
			start = start->prev;
		}
	}
}
