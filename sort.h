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

#endif
