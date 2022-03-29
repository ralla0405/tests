#include <stdio.h>
#include <algorithm>

int number, data[1000000];

int main(void) {

	// Enter N the number of N
	scanf("%d", &number);

	// Enter N numbers
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	
	// Sort
	std::sort(data, data + number);
	
	// Output
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	} 
	return 0;
}
