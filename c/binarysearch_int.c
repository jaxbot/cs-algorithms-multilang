#include <stdio.h>
#include <stdlib.h>

// Returns 1 if key found in array, 0 otherwise
// Worst case: O(log n)
// Best case: O(1)
int binary_search_int(int *array, int n, int key) {
	int hi = n - 1, lo = 0, mid, val;

	while (hi >= lo)
	{
		// Prevent integer overflow by computing an equivalent, but safer
		// operation
		mid = lo + (hi - lo) / 2;
		val = array[mid];

		if (val > key)
			hi = mid - 1;
		else if (val < key)
			lo = mid + 1;
		else
			return 1;
	}

	return 0;
}

// Returns -1 if not found, or the index if found
// Worse case: O(log n)
// Best case: O(1)
// Calls _ function with correct parameters
int recursive_binary_search_int(int *array, int n, int key) {
	return _recursive_binary_search_int(array, n, key, 0, n - 1);
}
int _recursive_binary_search_int(int *array, int n, int key, int lo, int hi) {
	int mid = lo + (hi - lo) / 2;

	if (hi < lo) return -1;
	
	if (key < array[mid]) {
		return _recursive_binary_search_int(array, n, key, lo, mid - 1);
	} else if (key > array[mid]) {
		return _recursive_binary_search_int(array, n, key, mid + 1, hi);
	}
	return mid;
}

// Test
int main(void) {

	int arr[15], key;
	arr[0] = 5;
	arr[1] = 8;
	arr[2] = 18;
	arr[3] = 28;
	arr[4] = 30;
	arr[5] = 31;
	arr[6] = 48;
	arr[7] = 58;
	arr[8] = 59;
	arr[9] = 61;
	arr[10] = 63;
	arr[11] = 68;
	arr[12] = 78;
	arr[13] = 88;
	arr[14] = 98;

	while (1) {
		printf("Search for: ");
		scanf("%d", &key);

		printf("%d\n", recursive_binary_search_int(arr, 16, key));
		printf("%d\n", binary_search_int(arr, 16, key));
	}

	return 0;
}

