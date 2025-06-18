#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;

#define X first
#define Y second

const int INF = 1e17;

int n, m, st, ed;
ll c;
vector<pair<ll, int>> adj[100'005];
priority_queue< pair<ll, int>,
	vector<pair<ll, int>>,
	greater<pair<ll, int>> > pq;
ll cost[100'005];
ll lo = 1, hi;

bool daijkstra(ll lim)
{
	fill(cost, cost + n + 1, INF);
	cost[st] = 0;
	pq.push({ cost[st], st });

	while (!pq.empty()) {
		ll c;
		int x;
		tie(c, x) = pq.top(); pq.pop();

		if (cost[x] != c) continue;
		for (auto nxt: adj[x]) {
			if (nxt.X > lim) continue;
			if (cost[nxt.Y] <= cost[x] + nxt.X) continue;
			cost[nxt.Y] = cost[x] + nxt.X;
			pq.push({ cost[nxt.Y], nxt.Y});
		}
	}
	if (cost[ed] > c) return 0;
	else return 1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> st >> ed >> c;
	while (m--) {
		int u, v; ll cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
		hi = max(cost, hi);
	}

	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (daijkstra(mid)) hi = mid;
		else lo = mid + 1;
	}

	if (daijkstra(lo)) cout << lo;
	else cout << -1;
	return 0;

}