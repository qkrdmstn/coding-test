#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

typedef long long ll;
const ll INF = 1e12;

int n, m;
vector<pair<ll, int>> adj[100005];
ll d[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adj[a].push_back({ i, b });
		adj[b].push_back({ i, a });
	}

	priority_queue< pair<ll, int>,
					vector<pair<ll, int>>,
					greater<pair<ll, int>>> pq;
	fill(d, d + n + 1, INF);
	d[1] = 0;
	pq.push({ d[1], 1 });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (d[cur.Y] != cur.X) continue; //이미 적혀있는 것과 비용이 다르면 갱신된 것이므로 pass
		for (auto nxt : adj[cur.Y]) { //현재 노드와 연결된 횡단보도 순회
			//다음 경로가 현재 기록된 시간보다 적으면 다음 주기에 대한 시간으로 기록
			if (nxt.X < cur.X)
				nxt.X += (((cur.X - nxt.X) / m) + 1) * m;
			//이미 기록된 것보다 오래걸리면 pass
			if (d[nxt.Y] <= nxt.X) continue;
			d[nxt.Y] = nxt.X;
			pq.push({ d[nxt.Y], nxt.Y });
		}
	}
	cout << d[n] << '\n';
	return 0;
}