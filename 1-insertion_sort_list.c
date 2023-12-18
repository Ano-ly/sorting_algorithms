#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list- This function sorts a list of integers in ascending
 * order
 * @list: pointer to the list to be sorted
 * Definition - this function uses the insertion sort algorithm to sort
 * a list of numbers in ascending order
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *Z;
	listint_t *A;
	listint_t *B;
	listint_t *store_z;
	int Z_n;

	Z = *list;
	while (Z != NULL)
	{
		Z_n = (int)Z->n;
		store_z = Z->next;
		A = Z->prev;
		if (A->prev)
			B = A->prev;
		else if (!A->prev)
			B = NULL;
		if ((A != NULL) && (A->n > Z_n))
		{
			if ((B != NULL) && (B->n < Z_n))
				insert_at_middle(list, B, Z);
			if ((B != NULL) && (B->n > Z_n))
				iterate_backwards(list, Z);
			else if (B == NULL)
				insert_at_start(list, Z);
		}
		else
		Z = store_z;
	}
}

/**
 * iterate_backwards - this function iterates backwards until a value
 * less than the current node is found
 * @list: pointer to the list to be iterated
 * @Z: pointer to the current node
 * @C: pointer to the node after the current node
 *
 * Definition: This function iterates bazkwards through the list
 * until NULL is reached or a node with a vaue less than the value
 * of the current node is reached. It then perfoems the insertion of the
 * node Z into the correct position, using two other functions.
 * Return: void
*/

void iterate_backwards(listint_t **list, listint_t *Z)
{
	listint_t *Y;

	Y = Z->prev;
	while ((Y->n > Z->n) && (Y != NULL))
		Y = Y->prev;
	if (Y == NULL)
		insert_at_start(list, Z);
	else
		insert_at_middle(list, Y, Z);
}

/**
 * insert_at_start - this function inserts a node at the start of the list
 * @list: list to be inserted in
 * @Z: current node to be inserted
 *
 * Definition: this function adds a node to the start of a list
 * Return: void
*/

void insert_at_start(listint_t **list, listint_t *Z)
{
	listint_t *C;

	C = Z->next;
	Z->next = *list;
	(*list)->prev =Z;
	(Z->next)->prev = Z->prev;
	(Z->prev)->next = C;
	Z->prev = NULL;
	*list = Z;
}

/**
 * insert_at_middle - this function inserts a node at the midde of two nodes
 * @list: list to be inserted in
 * @Y: node with value less than Z's value. Ordained to be Z's new prev
 * @Z: node to be inserted
 *
 * Definition - inserts at the middle of two nodes and performs necessary
 * reconnections
 * Return: void
*/

void insert_at_middle(listint_t **list, listint_t *Y, listint_t *Z)
{
	(void)list;

	(Z->prev)->next = Z->next;
	(Z->next)->prev = Z->prev;
	Z->next = Y->next;
	Z->prev = Y;
	(Y->next)->prev = Z;
	Y->next = Z;
}
