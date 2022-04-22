#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// visit array
int c[7];
vector<int> a[8];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
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

	// Perform BFS
	bfs(1);
	
	return 0;
}
