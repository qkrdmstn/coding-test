#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

//map[dir][i][j][k]: i층을 dir번 회전한 모습
int map[4][5][5][5];
int maze[5][5][5];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0, 1, -1 };

int BFS()
{
	int dist[5][5][5] = {};
	if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
		return 99999999;

	queue<tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push({ 0,0,0 });
	
	while (!q.empty()) {
		int curX, curY, curZ;
		tie(curX, curY, curZ) = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5)
				continue;
			if (dist[nx][ny][nz] != 0 || maze[nx][ny][nz] == 0)
				continue;
			if (nx == 4 && ny == 4 && nz == 4) {
				return dist[curX][curY][curZ];
			}

			q.push({ nx, ny, nz });
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
		}
	}

	return 99999999;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[0][i][j][k];
			}
		}

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				map[1][i][j][k] = map[0][i][4-k][j];
			}
		}

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				map[2][i][j][k] = map[1][i][4 - k][j];
			}
		}

		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				map[3][i][j][k] = map[2][i][4 - k][j];
			}
		}
	}

	int floor[5] = {0,1,2,3,4};
	int ans = 99999999;
	do
	{
		for (int temp = 0; temp < (1 << 2 * 5); temp++) {
			int brute = temp;
			for (int i = 0; i < 5; i++) {
				int dir = brute % 4;
				brute /= 4;

				for (int j = 0; j < 5; j++) {
					for (int k = 0; k < 5; k++) {
						maze[i][j][k] = map[dir][floor[i]][j][k];
					}
				}
			}
			ans = min(ans, BFS());
		}
	} while (next_permutation(floor, floor + 5));

	if (ans == 99999999)
		ans = -1;
	cout << ans;

	return 0;
}