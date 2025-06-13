#include <iostream>
using namespace std;

const int INF = 100'000'005;

int n, m;
int dist[105][105];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		fill(dist[i], dist[i] + n + 1, INF);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int i = 1; i <= n; i++) dist[i][i] = 0;

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++) {
				dist[st][ed] = min(dist[st][ed], dist[st][mid] + dist[mid][ed]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}