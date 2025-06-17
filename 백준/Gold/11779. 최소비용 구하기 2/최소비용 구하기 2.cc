#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

const int INF = 1e9+10;
int n, m;
int st, ed;
vector<pair<int, int>> adj[1005]; //{비용, 노드}
int d[1005];
int pre[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ c, v });
	}
	cin >> st >> ed;

	priority_queue< pair<int, int>,
					vector<pair<int, int>>,
					greater<pair<int, int>> > pq;

	fill(d, d + n + 1, INF);
	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		//if (cur.Y == ed) break;
		if (d[cur.Y] != cur.X) continue;
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
			pre[nxt.Y] = cur.Y;
		}
	}

	vector<int> path;
	int cur = ed;
	while (cur != st) {
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());

	cout << d[ed] << '\n';
	cout << path.size() << '\n';
	for (auto p : path) {
		cout << p << ' ';
	}
	return 0;
}