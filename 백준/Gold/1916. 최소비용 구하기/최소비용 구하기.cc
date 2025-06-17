#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int n, m;
int st,ed;
vector<pair<int, int>> adj[1005]; //{비용, 노드}
int d[1005];

int daijkstra(int st, int ed)
{
	priority_queue< pair<int, int>, 
					vector<pair<int, int>>, 
					greater<pair<int, int>> > pq;
	fill(d, d + n + 1, INF);
	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
	return d[ed];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		adj[u].push_back({ t,v });
	}
	cin >> st >> ed;
	cout << daijkstra(st, ed);

	return 0;
}