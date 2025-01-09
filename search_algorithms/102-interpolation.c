#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of ints
 * 						  using the Interpolation search algo
 * @array: pointer to the first element of the sorted array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is found, or -1 if not found or array is NULL
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, pos = 0;

	if (!array || size == 0)
		return (-1);
	/* calculate position using interpolation formula */
	pos = low + (((double)(high - low) / (array[high] - array[low]))
		  * (value - array[low]));
	while (low < high && value >= array[low] && value <= array[high])
	{
		/* print the comparison action */
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return (pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	printf("Value checked array[%lu] is out of range\n", pos);
	return (-1);
}
