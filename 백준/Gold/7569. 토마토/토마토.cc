#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;


int m, n, h;
queue<tuple<int, int, int>> q;
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int map[101][101][101];
int dist[101][101][101];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {

				cin >> map[i][j][k];
			
				dist[i][j][k] = -1;
				if (map[i][j][k] == 1) {
					q.push({ i,j,k });
					dist[i][j][k] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();

		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m)
				continue;
			if (map[nx][ny][nz] == -1 || dist[nx][ny][nz] != -1)
				continue;

			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			q.push({ nx, ny, nz });
		}
	}

	int maxDist = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {

				if (map[i][j][k] == 0 && dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				maxDist = max(maxDist, dist[i][j][k]);
			}
		}
	}
	cout << maxDist;
}