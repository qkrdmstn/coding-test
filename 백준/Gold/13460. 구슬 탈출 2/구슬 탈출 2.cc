#include <iostream>
#include <string>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
string board[10];
pair<int, int> bluePos, redPos;
int dist[11][11][11][11];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0,0,-1,1 };

int bfs()
{
	queue<tuple<int, int, int, int>> q;
	q.push({ bluePos.first, bluePos.second, redPos.first, redPos.second });
	dist[bluePos.first][bluePos.second][redPos.first][redPos.second] = 1;

	while (!q.empty()) {
		int bx, by, rx, ry;
		tie(bx, by, rx, ry) = q.front();
		q.pop();

		int cnt = dist[bx][by][rx][ry];
		if (cnt > 10)
			return -1;

		for (int dir = 0; dir < 4; dir++) {
			int n_bx = bx, n_by = by, n_rx = rx, n_ry = ry;

			while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.') {
				n_bx += dx[dir];
				n_by += dy[dir];
			}
			if (board[n_bx + dx[dir]][n_by + dy[dir]] == 'O')
				continue;

			while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.') {
				n_rx += dx[dir];
				n_ry += dy[dir];
			}

			if (board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O')
				return cnt;

			if ((n_bx == n_rx) && (n_by == n_ry)) {
				if (dir == 0)
					rx < bx ? n_bx++ : n_rx++;
				else if (dir == 1)
					rx > bx ? n_bx-- : n_rx--;
				else if (dir == 2)
					ry < by ? n_by++ : n_ry++;
				else
					ry > by ? n_by-- : n_ry--;
			}

			if (dist[n_bx][n_by][n_rx][n_ry] != -1)
				continue;
			dist[n_bx][n_by][n_rx][n_ry] = cnt + 1;
			q.push({ n_bx, n_by, n_rx, n_ry });
		}
	}
	return -1;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				redPos = { i,j };
				board[i][j] = '.';
			}
			if (board[i][j] == 'B') {
				bluePos = { i, j };
				board[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				fill(dist[i][j][k], dist[i][j][k] + m, -1);

	
	cout << bfs();

	return 0;
}