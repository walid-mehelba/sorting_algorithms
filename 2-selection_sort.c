#include "sort.h"

/**
  * selection_sort - sort array of integers using selection sort
  * @array: array of integers
  * @size: size of the array
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest, index;
	bool swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];
		swapped = false;

		for (j = i; j < size - 1; j++)
		{
			if (smallest > array[j + 1])
			{
				smallest = array[j + 1];
				index = j + 1;
				swapped = true;
			}
		}
		if (!swapped)
			continue;;
		array[index] = array[i];
		array[i] = smallest;
		print_array(array, size);
	}
}
