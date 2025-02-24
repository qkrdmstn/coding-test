#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int n, m, k;
string map[1001];
queue<tuple<int, int, int>> q;
int dist[1001][1001][11];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0, 0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	dist[0][0][k] = 1;
	q.push({ 0,0,k });

	while (!q.empty()) {
		int curX, curY, curK;
		tie(curX, curY, curK) = q.front();
		q.pop();
		if (curX == n - 1 && curY == m - 1) {
			cout << dist[curX][curY][curK];
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (map[nx][ny] == '1' && curK > 0 && dist[nx][ny][curK - 1] == 0) {
				int nk = curK - 1;
				dist[nx][ny][nk] = dist[curX][curY][curK] + 1;
				q.push({ nx, ny, nk });
			}
			else if (map[nx][ny] == '0' && dist[nx][ny][curK] == 0) {
				q.push({ nx, ny, curK });
				dist[nx][ny][curK] = dist[curX][curY][curK] + 1;
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}