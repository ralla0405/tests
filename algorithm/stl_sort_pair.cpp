#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	
	// Input
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "Tom"));
	v.push_back(pair<int, string>(93, "David"));
	v.push_back(pair<int, string>(97, "Erin"));
	v.push_back(pair<int, string>(87, "Logan"));
	v.push_back(pair<int, string>(92, "Olivia"));
	
	// Sort
	sort(v.begin(), v.end());
	
	// Output
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' ';
	} 
	return 0;
}

