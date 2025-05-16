#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
vector<int> adj[1005];
int dist[1005];

void bfs()
{
	queue<int> q;
	q.push(1);

	fill(dist, dist + n + 1, -1);
	dist[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (dist[cur] >= 2) continue;
		for (auto nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
			ans++;
		}
	}
}

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

	bfs();
	cout << ans;
	return 0;
}