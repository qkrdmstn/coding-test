#include <iostream>
#include <vector>
using namespace std;

const int INF = 10'000'005;

int n, m;
int dist[105][105];
int nxt[105][105];

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
		if (c < dist[a][b]) {
			dist[a][b] = c;
			nxt[a][b] = b;
		}
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++) {
				if (mid == st || mid == ed || st == ed) continue;
				if (dist[st][mid] + dist[mid][ed] < dist[st][ed]) {
					dist[st][ed] = dist[st][mid] + dist[mid][ed];
					nxt[st][ed] = nxt[st][mid];
				}
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << 0;
			else {
				int st = i;
				vector<int> path;
				while (st != j) {
					path.push_back(st);
					st = nxt[st][j];
				}
				path.push_back(j);
				cout << path.size() << ' ';
				for (auto p : path)
					cout << p << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}