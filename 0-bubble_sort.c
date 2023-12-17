#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Entry point
 *
 * Description: 'function that sorts an array using the bubble sort algorithm'
 * @array: int *array (array to be sorted)
 * @size: size_t size (Size of array)
 *
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	unsigned long int temp;


	for (j = 0; j < (size - 1); j++)
	{
		for (i = 0; i < (size - 1); i++)
		{
			if (array != NULL)
			{
				if (array[i] > array[i + 1])
				{
					temp = array[i];
					array[i] = array[i + 1];
					array[i + 1] = temp;
					print_array(array, size);
				}
			}
			else
			{
				return;
			}
		}
	}
}
