#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

string map[1001];
queue<tuple<int, int, int>> q;
int dist[1001][1001][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}

	q.push({0,0,0});
	dist[0][0][0] = dist[0][0][1] = 1;

	while (!q.empty()) {
		int curX, curY, curBroken;
		tie(curX, curY, curBroken) = q.front();
		if (curX == n - 1 && curY == m - 1) {
			cout << dist[curX][curY][curBroken];
			return 0;
		}
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];

			int nextDist = dist[curX][curY][curBroken] + 1;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (map[nx][ny] == '0' && dist[nx][ny][curBroken] == -1) {
				dist[nx][ny][curBroken] = nextDist;
				q.push({ nx, ny, curBroken });
			}
			if (!curBroken && map[nx][ny] == '1' && dist[nx][ny][1] == -1) {
				dist[nx][ny][1] = nextDist;
				q.push({ nx, ny, 1});
			}
		}
	}
	cout << -1;

	return 0;
}