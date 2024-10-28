#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* merge - Merge two sorted halves into one sorted array
* @array: Original array to sort
* @tmp: Temporary array to assist with merging
* @start: Starting index of the left sub-array
* @mid: Middle index where the array is split
* @end: Ending index of the right sub-array
*/
void merge(int *array, int *tmp, int start, int mid, int end)
{
int i = start, left = start, right = mid + 1;

while (left <= mid && right <= end)
{
if (array[left] <= array[right])
tmp[i++] = array[left++];
else
tmp[i++] = array[right++];
}

while (left <= mid)
tmp[i++] = array[left++];
while (right <= end)
tmp[i++] = array[right++];

printf("Merging...\n[left]: ");
print_array(&tmp[start], mid - start + 1);
printf("[right]: ");
print_array(&tmp[mid + 1], end - mid);
printf("[Done]: ");
print_array(&tmp[start], end - start + 1);

for (i = start; i <= end; i++)
array[i] = tmp[i];
}

/**
* mergesort - Recursive function to sort an array using Merge Sort
* @array: The array to sort
* @tmp: Temporary array for merging
* @start: Starting index of the current array section
* @end: Ending index of the current array section
*/
void mergesort(int *array, int *tmp, int start, int end)
{
int mid;

if (start >= end)
return;

mid = start + (end - start) / 2;

mergesort(array, tmp, start, mid);
mergesort(array, tmp, mid + 1, end);
merge(array, tmp, start, mid, end);
}

/**
* merge_sort - Sort an array of integers in ascending order using Merge Sort
* @array: Array of integers to sort
* @size: Size of the array
*/
void merge_sort(int *array, size_t size)
{
int *tmp;

if (!array || size < 2)
return;

tmp = malloc(size * sizeof(int));
if (!tmp)
return;

mergesort(array, tmp, 0, size - 1);
free(tmp);
}
