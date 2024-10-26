#include "sort.h"

/**
  * selection_sort - sort array of integers using selection sort
  * @array: array of integers
  * @size: size of the array
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];

		for (j = i; j < size - 1; j++)
		{
			if (smallest > array[j + 1])
			{
				smallest = array[j + 1];
				array[j + 1] = array[i];
				array[i] = smallest;
			}
		}
		print_array(array, size);
	}
}
