#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sort.h"

/**
 * partition - partitions an array or subarray
 * @array: the array or subarray being partitioned
 * @low: the first index
 * @high: the last index
 * @size: the size of the array
 *
 * Return: the index of the partition
*/


int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1), j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	if (array[high] != array[i + 1])
	{
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort - recursively sorts the array, using partition to form subarrays
 * @array: the array, or subarray, being sorted
 * @low: the lowest index of the current array
 * @high: the highest index of the current array
 * @size: the size of the array
*/

void sort(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = partition(array, low, high, size);

		sort(array, low, index - 1, size);
		sort(array, index + 1, high, size);
	}
}

/**
 * quick_sort - calls sort to recursively sort an array
 * @arr: the array to be sorted
 * @size: the size of the array
*/

void quick_sort(int *arr, size_t size)
{

	int high = size - 1, low = 0;

	sort(arr, low, high, size);
}
