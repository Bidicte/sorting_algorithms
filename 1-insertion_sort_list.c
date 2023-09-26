#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *noeud;

	if (list == NULL || (*list)->next == NULL)
		return;
	noeud = (*list)->next;
	while (noeud)
	{
		while ((noeud->prev) && (noeud->prev->n > noeud->n))
		{
			noeud = swap_node_func(noeud, list);
			print_list(*list);
		}
		noeud = noeud->next;
	}
}


/**
 *swap_node_func - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node_func(listint_t *noeud, listint_t **list)
{
	listint_t *back = noeud->prev, *current = noeud;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
