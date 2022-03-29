#include <iostream>
#include <algorithm>

using namespace std;

// Function ascending order
bool compare(int a, int b) {
	return a < b;
	// descending order
	// return a > b; 
}

int main(void) {
	
	// Input
	int a[10] = {2, 3, 10, 4, 8, 5, 1, 6, 7, 9};
	
	// Sort 
	sort(a, a + 10, compare);
	
	// Output
	for (int i = 0; i < 10; i++) {
		cout << a[i] << ' ';
	}
}

