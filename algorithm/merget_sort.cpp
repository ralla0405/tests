#include <stdio.h>

int number = 8;
int sorted[8]; // The sort arrays must be declared as global variables to use common memory.

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;
	
	// Insert into array in small order.
	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	
	// Insert remaining data.
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	
	// Insert sorted array.
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	// If the array size is 1
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	
	// Sort
	mergeSort(array, 0, number - 1);
	
	// Output
	for (int i = 0; i < number; i++) {
		printf("%d", array[i]);
	}
	return 0;
}
