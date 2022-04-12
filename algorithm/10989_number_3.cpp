#include <iostream>

using namespace std;

int n;
int a[10001];

int main(void) {
	
	// Input n
	scanf("%d", &n);
	
	// Input n variables and counting 
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	
	// Output
	for (int i = 0; i < 10001; i++) {
		while (a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		}
	}
	
	return 0;
}
