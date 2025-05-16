#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[20'005];
int dist[20'005];
vector<int> ans[20'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	queue<int> q;
	q.push(1);
	
	fill(dist, dist + 1 + n, -1);
	dist[1] = 0;

	int maxDist = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
			maxDist = dist[nxt];
			ans[dist[nxt]].push_back(nxt);
		}
	}

	sort(ans[maxDist].begin(), ans[maxDist].end());
	cout << ans[maxDist].front() << ' ' << maxDist << ' ' << ans[maxDist].size();

	return 0;
}