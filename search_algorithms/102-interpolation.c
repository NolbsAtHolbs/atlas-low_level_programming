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
	size_t low = 0, high = size - 1, pos;
	double fraction;

	if (!array || size == 0)
		return (-1);
	while (low <= high && value >= array[low] && value <= array[high])
	{
		if (array[high] == array[low])
			break; /* avoid % by 0 if same values */

		/* calculate position using interpolation formula */
		fraction = (double)(value - array[low]) / (array[high] - array[low]);
		pos = low + (size_t)((high - low) * fraction);

		if (pos >= size)
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break; /* stop searching */
		} /* print the comparison action */
		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
			return ((int)pos);
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos;
	}
	if (low < size && array[low] == value)
		return ((int)low); /* last check if low is w/in bounds & matches val */
	return (-1);
}
