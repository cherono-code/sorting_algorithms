#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: the pointer to the head of a doubly-linked list of integers.
 * @tail: the pointer to the tail of the doubly-linked list.
 * @shaker: the pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmpp;
	else
		*list = tmpp;
	tmpp->prev = (*shaker)->prev;
	(*shaker)->next = tmpp->next;
	if (tmpp->next != NULL)
		tmpp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmpp;
	tmpp->next = *shaker;
	*shaker = tmpp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: the pointer to the head of a doubly-linked list of integers.
 * @tail: the pointer to the tail of the doubly-linked list.
 * @shaker: the pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmpp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmpp;
	else
		*tail = tmpp;
	tmpp->next = (*shaker)->next;
	(*shaker)->prev = tmpp->prev;
	if (tmpp->prev != NULL)
		tmpp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmpp;
	tmpp->prev = *shaker;
	*shaker = tmpp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list:the pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}

