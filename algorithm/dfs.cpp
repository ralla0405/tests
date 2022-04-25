#include <iostream>
#include <vector>

using namespace std;

// visit array
int c[7];
vector<int> a[8];

void dfs(int x) {
	if (c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

int main(void) {
	// Connect 1 and 2
	a[1].push_back(2);
	a[2].push_back(1);
	
	// Connect 1 and 3
	a[1].push_back(3);
	a[3].push_back(1);
	
	// Connect 2 and 3
	a[2].push_back(3);
	a[3].push_back(2);
	
	// Connect 2 and 4
	a[2].push_back(4);
	a[4].push_back(2);
	
	// Connect 2 and 5
	a[2].push_back(5);
	a[5].push_back(2);
	
	// Connect 3 and 6
	a[3].push_back(6);
	a[6].push_back(3);
	
	// Connect 3 and 7
	a[3].push_back(7);
	a[7].push_back(3);
	
	// Connect 4 and 5
	a[4].push_back(5);
	a[5].push_back(4);
	
	// Connect 6 and 7
	a[6].push_back(7);
	a[7].push_back(6);

	// Perform DFS
	dfs(1);
	
	return 0;
}
