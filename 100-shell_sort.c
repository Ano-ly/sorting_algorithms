#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * shell_sort - Entry point
 *
 * Description: 'Function that sorts an array using shell sort'
 * @array: int *array (array to be sorted)
 * @size: size_t size (size of said array)
 * Return: Always 0 (Success)
 */
void shell_sort(int *array, size_t size)
{
	unsigned long int i, j;
	unsigned long int interval = 1;
	unsigned long int intcount = 1;
	unsigned long int intbuff = 1;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (intbuff < size)
	{
	interval = intbuff;
	intbuff = (power(3, intcount) - 1) / 2;
	intcount++;
	}

	while (interval > 0)
	{
		for (i = interval; i < (size); i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		interval = interval / 3;
		print_array(array, size);
	}
	return;

}

/**
 * power - Entry point
 *
 * Description: 'Function that returns a number raised to a power'
 * @value: int value (value to be raised)
 * @power: int power (value by which it is raised)
 * Return: value
 */
int power(int value, int power)
{
	int j;
	int temppower = value;

	for (j = 0; j < power; j++)
	{
		value = value * temppower;
	}
	return (value);
}
