#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m;
int dist[205][205];
int nxt[205][205];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (c < dist[a][b]) {
			dist[a][b] = c;
			dist[b][a] = c;
			nxt[a][b] = b;
			nxt[b][a] = a;
		}
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int ed = 1; ed <= n; ed++) {
				if (dist[st][mid] + dist[mid][ed] < dist[st][ed]) {
					nxt[st][ed] = nxt[st][mid];
					dist[st][ed] = dist[st][mid] + dist[mid][ed];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF || dist[i][j] == 0)
				cout << "- ";
			else
				cout << nxt[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;

	/*
	nxt 배열 만들기
	주의할 점: st에서 ed로 mid를 거쳐가는 경로로 nxt를 업데이트할 때
	nxt[st][ed] = nxt[st][mid];를 해야 함.
	*/
}