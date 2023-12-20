#ifndef SORT_H
#define SORT_H

#include "hash.h"

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void insertion_sort_list(listint_t **list);
void iterate_backwards(listint_t **list, listint_t *Z);
void insert_at_start(listint_t **list, listint_t *Z);
void insert_at_middle(listint_t **list, listint_t *Y, listint_t *Z);

void selection_sort(int *array, size_t size);
int mathmin(int *array, size_t size, unsigned long int counter);


void quick_sort(int *array, size_t size);
void sort_recursive(int *array, size_t start, size_t end, size_t size);
size_t surround_pivot(int *array, size_t start, size_t end, size_t size);
void two_switch(int *array, size_t ind1, size_t ind2, size_t size);
void swap_em(int *array, size_t swap1, size_t swap2, size_t size);
int check_sorted(int *array, size_t size);

#endif
