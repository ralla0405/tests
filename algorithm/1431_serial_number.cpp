#include <iostream>
#include <algorithm>
<<<<<<< HEAD
#include <vector>

using namespace std;

int n;
vector <string> v;
=======

using namespace std;

string a[20000];
int n;
>>>>>>> d1a4142161f89d5f33e0a6519f9a04d995f8bc1e

int getSum(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		// If a is number
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b) {
	// If the length is shorter
	if (a.length() < b.length()) {
		return 1;
	} else if (a.length() > b.length()) {
		return 0;
	}
	// If the lengths are the same
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// If the sum of the numbers in a eltter is different 
		if (aSum != bSum) {
			return aSum < bSum;
		} else {
			return a < b;
		}
	}
}

int main(void) {
	
	// Input n
	cin >> n;
	
	// Input n variables
<<<<<<< HEAD
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}
	
	// Sort
	sort(v.begin(), v.end(), compare);
	
	// Output
	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
=======
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
>>>>>>> d1a4142161f89d5f33e0a6519f9a04d995f8bc1e
	}
	
	return 0;
}
