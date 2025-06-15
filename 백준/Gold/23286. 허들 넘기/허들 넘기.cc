#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, t;
int cost[305][305];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		fill(cost[i], cost[i] + n + 1, INF);
		cost[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int u, v, h;
		cin >> u >> v >> h;
		cost[u][v] = h;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++) {
				cost[st][ed] = min(cost[st][ed], max(cost[st][mid], cost[mid][ed]));
			}
		}
	}

	while (t--) {
		int s, e;
		cin >> s >> e;
		if (cost[s][e] == INF) cout << -1 << '\n';
		else cout << cost[s][e] << '\n';
	}

	return 0;
	/*
	경로 중 가장 높은 허들의 높이가 최소가 되도록 하려면
	플로이드 알고리즘에서, cost[st][ed] = min(cost[st][ed], max(cost[st][mid], cost[mid][ed]));
	를 수행하면 된다.
	이는 거쳐가는 경로 [st,mid] ~ [mid,ed] 중 가장 높은 허들과 현재 기록된 경로 중 가장 높은 허들을 비교해
	더 낮은 경로를 택하는 방식이다.
	*/
}