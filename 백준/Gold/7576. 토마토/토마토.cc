#include<iostream>
#include<queue>
using namespace std;

int m, n;
int arr[1001][1001];
int dist[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
queue<pair<int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({ i,j });
			if (arr[i][j] == 0)
				dist[i][j] = -1;
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == -1 || dist[nx][ny] != -1) continue;

			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] > max)
				max = dist[i][j];
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << max;
	return 0;
}