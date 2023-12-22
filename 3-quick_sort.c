#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			printf("Swapped: %d, %d\n", array[i], array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	printf("Swapped: %d, %d\n", array[i + 1], array[high]);

	(void)size; // Unused parameter warning

	return i + 1;
}

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

int main(void)
{
	int array[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 95, 31, 20, 22, 98, 39, 92, 41, 62, 1};
	size_t size = sizeof(array) / sizeof(array[0]);

	printf("Original array: ");
	for (size_t i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");

	quick_sort(array, size);

	printf("Sorted array: ");
	for (size_t i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}
