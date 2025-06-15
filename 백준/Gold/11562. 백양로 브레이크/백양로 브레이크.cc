#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, k;
int dist[255][255];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int u, v, b;
		cin >> u >> v >> b;

		dist[u][v] = 0;

		//일방 통행이면 비용 적용
		if (b == 0) dist[v][u] = 1;
		else dist[v][u] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++)
				dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
		}
	}

	cin >> k;
	while (k--) {
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}
	return 0;
}