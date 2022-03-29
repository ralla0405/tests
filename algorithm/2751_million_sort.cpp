#include <stdio.h>

int number, data[1000000];

void quickSort(int *data, int start, int end) {
	
	// If there is one element, the function is terminated. 
	if (start >= end) {
		return;
	}
	
	// Key is the first element.
	int key = start; 
	int i = start + 1, j = end, temp;
	
	// Repeat until corssed.
	while (i <= j) {
		// Until a value greater than the key value is found
		while (data[i] <= data[key]) {
			i++; 
		}
		// Until a value less than the key value is found
		while (data[j] >= data[key] && j > start) {
			j--; 
		}
		// Replace the key value if it is currently crossed.
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		} 
		// Replace i value and j value if it doesn't cross.
		else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
		
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main(void) {

	// Enter the number of N
	scanf("%d", &number);

	// Enter N numbers
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	
	// Sort 
	quickSort(data, 0, number - 1);
	
	// Output
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	} 
	return 0;
}
