#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
vector<int> adj[101'005];
int dist[101'005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			int x;
			cin >> x;
			adj[n + i].push_back(x);
			adj[x].push_back(n + i);
		}
	}

	fill(dist, dist + n + m + 1, -1);

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nxt : adj[cur]) {
			if (dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}

	if (dist[n] == -1) cout << dist[n];
	else cout << dist[n] / 2 + 1;

	return 0;

	/*
	하이퍼튜브에 연결된 모든 역을 간선으로 연결하면 시간초과 (간선이 너무 많아짐)
	하이퍼튜브를 n+i번째 정점으로 취급하여 각 역에서 튜브를 거쳐 다음 역으로 이동하는 방식으로
	그래프를 설계하고 bfs로 순회하여 거리를 측정
	-> 이때 각 역을 이동할 때마다 튜브를 거치기 때문에 최종 결과에서는 거리 / 2 + 1을 해야 튜브를 제외한
	거리가 도출됨
	*/
}