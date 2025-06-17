#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;

int n, m;
int st, mid1, mid2, ed;
vector<pair<int, int>> adj[1005]; //{비용, 노드}
int d[1005];

ll daijkstra(int st, int ed)
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
		adj[v].push_back({ t,u });
	}
	cin >> mid1 >> mid2;

	ll ans1 = daijkstra(1, mid1) + daijkstra(mid1, mid2) + daijkstra(mid2, n);
	ll ans2 = daijkstra(1, mid2) + daijkstra(mid2, mid1) + daijkstra(mid1, n);
	ll ans = min(ans1, ans2);

	if (ans >= INF) cout << -1;
	else cout << ans;
	return 0;
}