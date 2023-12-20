#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void shell_sort(int *array, size_t size)
{
	long unsigned int i, j;
	long unsigned int interval = 1;
	long unsigned int intcount = 1;
	long unsigned int intbuff = 1;
	int temp;
	

	if (array == NULL || size < 2){
		return;
	}

	while (intbuff < size){
	interval = intbuff;
	intbuff = (power(3, intcount) - 1)/2;
	intcount++;
	}

	while (interval > 0)
	{
		for (i=interval; i < (size); i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j-interval];
			}
			array[j] = temp;
		}
		interval = interval/3;
		print_array(array, size);
	}
	
	return;

}

int power(int value, int power)
{
	int j;
	int temppower = value;
	for (j = 0; j < power; j++)
	{
		value=value * temppower;
	}
	return value;
}
