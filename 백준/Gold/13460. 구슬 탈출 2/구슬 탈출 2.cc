#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int BFS(pair<int, int> redPos, pair<int, int> bluePos, string board[], int n, int m)
{
	queue<tuple<int, int, int, int>> q;
	int dist[10][10][10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				fill(dist[i][j][k], dist[i][j][k] + 10, -1);

	int rx, ry, bx, by;
	tie(rx, ry) = redPos;
	tie(bx, by) = bluePos;

	q.push({ rx, ry, bx, by });
	dist[rx][ry][bx][by] = 0;

	while (!q.empty())
	{
		int crx, cry, cbx, cby;
		tie(crx, cry, cbx, cby) = q.front(); q.pop();

		if (dist[crx][cry][cbx][cby] >= 10) break;
		for (int i = 0; i < 4; i++)
		{
			int nrx = crx, nry = cry, nbx = cbx, nby = cby;

			//파란 구슬을 먼저 움직여 탈출하는지 확인
			while (board[nbx + dx[i]][nby + dy[i]] == '.')
			{
				nbx += dx[i];
				nby += dy[i];
			}
			if (board[nbx + dx[i]][nby + dy[i]] == 'O')
			continue;

			//빨간 구슬 이동
			while (board[nrx + dx[i]][nry + dy[i]] == '.')
			{
				nrx += dx[i];
				nry += dy[i];
			}
			if (board[nrx + dx[i]][nry + dy[i]] == 'O')
				return dist[crx][cry][cbx][cby] + 1;

			//마지막 위치가 겹치면 초기 위치에 기반해서 조정
			if (nrx == nbx && nry == nby)
			{
				if (i == 0)
					cry < cby ? nry-- : nby--;
				else if (i == 1)
					crx < cbx ? nrx-- : nbx--;
				else if (i == 2)
					cry > cby ? nry++ : nby++;
				else if (i == 3)
					crx > cbx ? nrx++ : nbx++;
			}
			if (dist[nrx][nry][nbx][nby] >= 0) continue;

			q.push({ nrx, nry, nbx, nby });
			dist[nrx][nry][nbx][nby] = dist[crx][cry][cbx][cby] + 1;
		}
	}
	return -1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	string board[10];

	pair<int, int> redPos;
	pair<int, int> bluePos;
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'R')
			{
				redPos = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B')
			{
				bluePos = { i, j };
				board[i][j] = '.';
			}
		}
	}

	cout << BFS(redPos, bluePos, board, n, m);
	return 0;
}