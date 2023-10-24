#include "sort.h"


/**
 * swap - swaping values
 * @a: the first address
 * @b: the second address
 * Return: nothing
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto - lomuto partitioning
 * @array: the array
 * @low: the lower value
 * @high: the higher value
 * @size: the size of the array
 * Return: the iteration less 1
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * _quick - sub quick sort function
 * @array: the array to sort
 * @low: the low
 * @high: the higher
 * @size: the size of the array
 * Return: nothing
 */
void _quick(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto(array, low, high, size);
		_quick(array, low, pi - 1, size);
		_quick(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - implementation of the quick sort algor
 * @array: the array to sort
 * @size: the size of the array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_quick(array, 0, size - 1, size);
}
