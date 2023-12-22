#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size <= 1)
		return; /* Base case: array with 0 or 1 element is already sorted */

	size_t pivot = partition(array, size);
	quick_sort(array, pivot);
	quick_sort(array + pivot + 1, size - pivot - 1);
}

/**
 * partition - Partitions an array using the Lomuto partition scheme
 * @array: The array to be partitioned
 * @size: The size of the array
 * Return: The index of the pivot element after partitioning
 */
size_t partition(int *array, size_t size)
{
	int pivot = array[size - 1];
	int temp;
	size_t i = 0, j;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
	}

	/* Swap pivot with element at i */
	temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;

	print_array(array, size);

	return i;
}
