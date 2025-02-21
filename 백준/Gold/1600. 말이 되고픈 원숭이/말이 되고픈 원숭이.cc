#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int k, w, h;
queue<tuple<int, int, int>> q;
int map[201][201];
int dist[201][201][32];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dhx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dhy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
			for (int l = 0; l <= k; l++) {
				dist[i][j][l] = -1;
			}
		}
	}

	dist[0][0][0] = 0;
	q.push({ 0,0,0 });

	while (!q.empty())
	{
		int curX, curY, curK;
		tie(curX, curY, curK) = q.front();
		q.pop();
		if (curK < k) {
			for (int dir = 0; dir < 8; dir++) {
				int nx = curX + dhx[dir];
				int ny = curY + dhy[dir];
				int nk = curK + 1;

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (map[nx][ny] != 0 || dist[nx][ny][nk] != -1)
					continue;

				dist[nx][ny][nk] = dist[curX][curY][curK] + 1;
				q.push({ nx, ny, nk });
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nk = curK;

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;
			if (map[nx][ny] != 0 || dist[nx][ny][nk] != -1)
				continue;

			dist[nx][ny][nk] = dist[curX][curY][curK] + 1;
			q.push({ nx, ny, nk });
		}
	}

	int ans = 10000000;
	for (int i = 0; i <= k; i++) {
		if (dist[h - 1][w - 1][i] != -1 && dist[h - 1][w - 1][i] < ans) {
			ans = dist[h - 1][w - 1][i];
		}
	}
	if (ans != 10000000)
		cout << ans;
	else
		cout << -1;
	return 0;
}