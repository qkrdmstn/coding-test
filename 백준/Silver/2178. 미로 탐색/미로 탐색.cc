#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
string arr[101] = {};
int dist[101][101] = {};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	dist[0][0] = 1; //첫 번째 칸도 1의 거리를 가짐

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] != '1' || dist[nx][ny] != 0)
				continue;

			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}

	cout << dist[n - 1][m - 1];
	return 0;
}