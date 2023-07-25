#include "sort.h"

/**
 * swap_nodes - swaps two nodes
 * @node1: the node to swap
 * @node2: the node to swap
 * @head: the pointer to head node
 * Return: void
 */

void swap_nodes(listint_t *node1, listint_t *node2, listint_t **head)
{
	listint_t *tmp = node1->prev;

	if (tmp != NULL)
		tmp->next = node2;
	node2->prev = tmp;
	node1->prev = node2;
	node1->next = node2->next;
	node2->next = node1;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev == NULL)
		*head = node2;
}

/**
  * len_list - computes lenght of linked list
  * @list: head node of list
  * Return: lenght of the list
  */

int len_list(listint_t *list)
{
	int res = 0;

	while (list)
	{
		res++;
		list = list->next;
	}
	return (res);
}

/**
 * cocktail_sort_list - cocktail sorting algo
 * @list: pointer to list to sort
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	int start = 0, end, flag = 1, counter = 0;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tmp = *list;
	end = len_list(*list);
	while (flag)
	{
		flag = 0;
		while (counter < end - 1)
		{
			if (tmp->n > tmp->next->n)
			{
				flag = 1;
				swap_nodes(tmp, tmp->next, list);
				print_list(*list);
			}
			else
				tmp = tmp->next;
			counter++;
		}
		end--;
		if (flag == 0)
			break;
		flag = 0;
		while (counter > start)
		{
			if (tmp->n < tmp->prev->n)
			{
				flag = 1;
				swap_nodes(tmp->prev, tmp, list);
				print_list(*list);
			}
			else
				tmp = tmp->prev;
			counter--;
		}
		start++;
	}
}
