#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	// If the length is shorter
	if (a.length() < b.length()) {
		return 1;
	} else if (a.length() > b.length()) {
		return 0;
	}
	// If the lengths are the same
	else {
		return a < b;
	}
}

int main(void) {
	
	// Input n
	cin >> n;
	
	// Input n variables
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// Sort
	sort(a, a + n, compare);
	
	// Output
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		} else {
			cout << a[i] << '\n';
		}
	}
	
	return 0;
}
