#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second 

const int MXN = 20005;
const int INF = 1e9 + 10;

int v, e, st;
vector<pair<int, int>> adj[MXN];
int d[MXN];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w,v });
	}

	priority_queue< pair<int, int>, 
					vector<pair<int, int>>, 
					greater<pair<int, int>> > pq;
	d[st] = 0;
	pq.push({ d[st], st});
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		//현재 작성된 테이블과 다른 원소라면 pass
		if (d[cur.Y] != cur.X) continue;

		//선택된 노드과 연결된 노드를 순회
		for (auto nxt : adj[cur.Y]) {
			if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;

			//선택된 노드를 거쳐가는 게 더 적은 비용이라면 갱신하고 큐에 삽입
			d[nxt.Y] = d[cur.Y] + nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}
	return 0;
}