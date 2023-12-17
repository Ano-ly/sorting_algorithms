#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	long unsigned int temp;


	for (j = 0; j < (size-1); j++){
		for (i = 0; i < (size-1); i++){
			if (array != NULL)
			{
				if (array[i] > array[i+1])
				{
					temp = array[i];
					array[i] = array[i+1];
					array[i+1] = temp;
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
