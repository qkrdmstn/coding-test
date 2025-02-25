#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
string map[1001];
queue<tuple<int, int, int, int>> q;
int dist[1001][1001][11][2]; //0:낮, 1:밤
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	q.push({ 0,0, k, 0 });
	dist[0][0][k][0] = 1;

	while (!q.empty()) {
		int curX, curY, curK, curT;
		tie(curX, curY, curK, curT) = q.front();
		q.pop();

		if (curX == n - 1 && curY == m - 1) {
			cout << dist[curX][curY][curK][curT];
			return 0;
		}

		int nt = 1 - curT;
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == '1') { //벽인 경우
				if (curK == 0)
					continue;

				if (curT == 0) { //현재 낮이면
					int nk = curK - 1;
					if (dist[nx][ny][nk][nt] > 0)
						continue;
					q.push({ nx, ny, nk, nt });
					dist[nx][ny][nk][nt] = dist[curX][curY][curK][curT] + 1;
				}
				else  { //밤이면 제자리에 머무르기
					int nk = curK;
					if (dist[curX][curY][nk][nt] > 0)
						continue;
					q.push({ curX, curY, nk, nt });
					dist[curX][curY][nk][nt] = dist[curX][curY][curK][curT] + 1;
				}
			}
			else {
				int nk = curK;
				if (dist[nx][ny][nk][nt] > 0)
					continue;
				q.push({ nx, ny, nk, nt });
				dist[nx][ny][nk][nt] = dist[curX][curY][curK][curT] + 1;
			}
		}
	}
	cout << -1;
	return 0;
}