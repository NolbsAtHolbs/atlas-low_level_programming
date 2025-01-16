#include "search_algos.h"

int ranged_bin_search(const int *array, size_t left, size_t right, int value);
void print_subarray(const int *array, size_t left, size_t right);

/**
 * print_subarray - prints the subarray elements currently being searched
 * @array: pointer to the first element of the array
 * @left: left index of the subarray
 * @right: right index of the subarray
 */
void print_subarray(const int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * ranged_bin_search - performs binary search within [left, right]
 * @array: pointer to the first element of the entire array
 * @left: left boundary of the subarray
 * @right: right boundary of the subarray
 * @value: value to search for
 * Return: index where value is found, or -1 if not found
 */
int ranged_bin_search(const int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		print_subarray(array, left, right);
		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
		{
			if (mid == 0)
				break;
			right = mid - 1;
		}
	}
	return (-1);
}

/**
 * expntl_search - search for value in sorted array w/ expntl search, then bnry
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 * Return: first index where value is found, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, prev, high;
	int idx;

	if (!array || size == 0)
		return (-1);
	if (array[0] == value)
		return (0);
	bound = 1;
	while (bound < size && array[bound] < value)
	{ /* Find range by powers of 2 */
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	prev = bound / 2;
	if (bound < size)
		high = bound;
	else
		high = size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", prev, high);
	idx = ranged_bin_search(array, prev, high, value);
	return (idx);
} /* binary search within [prev, high] */
