#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// pair<name, pair<score, age>>
bool compare(pair<string, pair<int, int> > a,
			 pair<string, pair<int, int> > b) {
	// Compare score 
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	} else {
		return a.second.first > b.second.first;
	}
}
			 
int main(void) {
	
	// Input
	vector<pair<string, pair<int, int> > > v;
	v.push_back(pair<string, pair<int, int> >("Tom", make_pair(90, 19910304)));
	v.push_back(pair<string, pair<int, int> >("David", make_pair(92, 19900405)));
	v.push_back(pair<string, pair<int, int> >("Erin", make_pair(97, 19950824)));
	v.push_back(pair<string, pair<int, int> >("Logan", make_pair(87, 19920402)));
	v.push_back(pair<string, pair<int, int> >("Olivia", make_pair(92, 19910508)));
	
	// Sort
	sort(v.begin(), v.end(), compare);
	
	// Output
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	} 
	return 0;
}

