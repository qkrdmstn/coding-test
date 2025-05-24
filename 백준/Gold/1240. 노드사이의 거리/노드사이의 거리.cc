#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
vector<pair<int, int>> adj[100'005];
int dist[100'005];

int bfs(int st, int ed)
{
	queue<int> q;
	fill(dist, dist + n + 1, -1);

	q.push(st);
	dist[st] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			int n, d;
			tie(n, d) = nxt;

			if (dist[n] != -1) continue;
			dist[n] = dist[cur] + d;
			q.push(n);
		}
	}

	return dist[ed];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({ v, d });
		adj[v].push_back({ u, d });
	}

	for (int i = 0; i < m; i++) {
		int st, ed;
		cin >> st >> ed;
		cout << bfs(st, ed) << '\n';
	}
	return 0;
}