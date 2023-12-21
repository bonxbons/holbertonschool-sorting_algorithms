#include "sort.h"

void quick_sort(int *array, size_t size)
{
    if (size <= 1) {
        return;  /* Base case: array with 0 or 1 element is already sorted */
    }

    size_t pivot_index = partition(array, size);
    quick_sort(array, pivot_index);
    quick_sort(array + pivot_index + 1, size - pivot_index - 1);
}

size_t partition(int *array, size_t size){
    int pivot = array[size - 1];
    size_t i = 0;

    for (size_t j = 0; j < size - 1; j++) {
        if (array[j] <= pivot) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
        }
    }

    // Swap pivot with element at i
    int temp = array[i];
    array[i] = array[size - 1];
    array[size - 1] = temp;

    print_array(array, size);

    return i;
}

