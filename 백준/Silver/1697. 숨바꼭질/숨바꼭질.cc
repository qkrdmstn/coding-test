#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int dist[100001];

int main(void)
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 100001; i++) {
		dist[i] = -1;
	}

	q.push(n);
	dist[n] = 0;
	
	while (dist[k] == -1) {
		int cur = q.front();
		q.pop();

		for (int next : {cur - 1, cur + 1, 2 * cur}) {
			
			if (next < 0 || next >= 100001)
				continue;
			if (dist[next] != -1)
				continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}

	cout << dist[k];
	return 0;
}