#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Entry point
 *
 * Description: 'sorts an array using the selection sort algorithm'
 * @array: int *array (array to be sorted)
 * @size: size_t size (Size of array)
 *
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i;
	int j;
	int temp;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; i < (size - 1); i++)
	{
		j = mathmin(array, size, i);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
 * mathmin - Entry point
 *
 * Description: 'returns a pointer to the lowest value in an array of ints'
 * @array: int *array (array being sorted)
 * @size: size_t size (Size of array)
 * @counter: unsigned long int counter
 * (counter indicates the starting point from which the array is counted from)
 *
 * Return: Always 0
 */
int mathmin(int *array, size_t size, unsigned long int counter)
{
	int min = array[counter];
	int temp = counter;

	for (; counter < (size); counter++)
	{
		if (array[counter] < min)
		{
			min = array[counter];
		}
	}
	for (counter = temp; counter < (size); counter++)
	{
		if (min == array[counter])
		{
			return (counter);
		}
	}
	return (counter);
}
