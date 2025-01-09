#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array
 *                       using the Interpolation search algorithm
 * @array: pointer to the first element of the sorted array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is found, or -1 if not found or array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t pos = 0, low = 0, high = size - 1;

	if (!array || size == 0)
		return (-1);
	pos = low + (((double)(high - low) / (array[high] - array[low]))
		  * (value - array[low]));
	while (low <= high && value >= array[low] && value <= array[high])
	{
		if (pos < size)
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		else
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			return (-1);
		}
		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
			low = pos++;
		else
			high = pos--;
	}
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);
}
