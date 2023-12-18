#include "hash.h"

void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void iterate_backwards(listint_t **list, listint_t *Z);
void insert_at_start(listint_t **list, listint_t *Z);
void insert_at_middle(listint_t **list, listint_t *Y, listint_t *Z);
