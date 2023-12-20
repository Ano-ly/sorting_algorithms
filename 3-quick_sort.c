#include <stdlib.h>
#include "sort.h"


/**
 * quick_sort - sorts an array using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 *
 * Definition - sorts an array
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
	sort_recursive(array, 0, size - 1, size);
}

/**
 * sort_recursive - sorts an array using recursion
 * @array: array to be sorted
 * @start: starting point of sorting
 * @end: ending point or index of sorting
 * @size: size of the array
 *
 * Description - sorts an array using recursion and a 'surround pivot'
 * function
 * Return: void
*/

void sort_recursive(int *array, size_t start, size_t end, size_t size)
{
	size_t spot;

	if (start > end)
		return;
	spot = surround_pivot(array, start, end, size);
	if (check_sorted(array, size) == 1)
		return;
	if (spot > 0)
		sort_recursive(array, start, spot - 1, size);
	if (start != end)
		sort_recursive(array, spot + 1, end, size);
}

/**
 * surround_pivot - this function uses the Lomuto partition
 * algorithm to sort an array
 * @array: array to be sorted
 * @start: starting point or index
 * @end: end point or index
 * @size: size of array
 *
 * Description - uses the Lomuto partition algorithm to sort
 * an array of integers
 * Return: integer; index of pivot
*/

size_t surround_pivot(int *array, size_t start, size_t end, size_t size)
{
	size_t grim;
	int piv;
	size_t iter;

	if (start == end)
	{
		two_switch(array, start - 1, end, size);
		return 0;
	}
	grim = start - 1;
	piv = array[end];

	for (iter = start; iter < end; iter++)
	{
		if (array[iter] <= piv)
		{
			grim++;
			swap_em(array, grim, iter, size);
		}
	}
	swap_em(array, grim + 1, end, size);
	return (grim + 1);
}

/**
 * two_switch - switches two integers' positions based on their
 * relative size.
 * @array: array containing integers to be switched
 * @ind1: the index of first integer
 * @ind2: the index of second integer
 * @size: size of array
 *
 * Description - takes an arry as argument, and two indices, and switches
 * the values of the array at those indices based on their relative size.
 * Return: void
*/

void two_switch(int *array, size_t ind1, size_t ind2, size_t size)
{
	size_t store_ind1;

	store_ind1 = ind1;

	if (array[ind1] <= array[ind2])
		return;
	else
	{
		array[ind1] = array[ind2];
		array[ind2] = store_ind1;
		print_array(array, size);
	}
}

/**
 * swap_em - swaps two indices in an array
 * @array: array with indices to be swapped
 * @swap1: index of one integer to be swapped
 * @swap2: index of other integer to be swapped with swap1
 * @size: size of array
 *
 * Definition - swaps two values in an array
 * Return: void
*/

void swap_em(int *array, size_t swap1, size_t swap2, size_t size)
{
	int s;

	if (array[swap1] == array[swap2])
		return;
	s = array[swap1];
	array[swap1] = array[swap2];
	array[swap2] = s;
	print_array(array, size);
}

/**
 * check_sorted - checks if an array has been sorted
 * @array: array to be checked
 *
 * Definition - checks if an array has been sorted in ascending order
 * Return: 1 if sorted, 0 if not
*/

int check_sorted(int *array, size_t size)
{
	size_t iter;

	for (iter = 0; iter < size - 1; iter++)
	{
		if (array[iter + 1] >= array[iter])
			continue;
		else
			return (0);
	}
	return (1);
}
