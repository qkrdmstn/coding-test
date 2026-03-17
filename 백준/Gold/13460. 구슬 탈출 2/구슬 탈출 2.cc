#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

//상하좌우
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int BFS(string board[15], vector<pair<int, int>>& pos)
{
	queue<tuple<int, int, int, int>> q;
	int dist[15][15][15][15];
	for(int i=0; i<15; i++)
		for(int j=0; j<15; j++)
			for(int k=0; k<15; k++)
				fill(dist[i][j][k], dist[i][j][k] + 15, -1);
	q.push({ pos[0].first, pos[0].second, pos[1].first, pos[1].second });
	dist[pos[0].first][pos[0].second][pos[1].first][pos[1].second] = 1;

	while (!q.empty())
	{
		int bx, by, rx, ry;
		tie(bx, by, rx, ry) = q.front(); q.pop();

		int cnt = dist[bx][by][rx][ry];
		if (cnt > 10)
			return -1;

		for (int i = 0; i < 4; i++)
		{
			int nbx = bx, nby = by, nrx = rx, nry = ry;
			while (board[nbx + dx[i]][nby + dy[i]] == '.')
			{
				nbx += dx[i];
				nby += dy[i];
			}
			if (board[nbx + dx[i]][nby + dy[i]] == 'O')
				continue;

			while (board[nrx + dx[i]][nry + dy[i]] == '.')
			{
				nrx += dx[i];
				nry += dy[i];
			}
			if (board[nrx + dx[i]][nry + dy[i]] == 'O')
				return cnt;

			if ((nbx == nrx) && (nby == nry))
			{
				if (i == 0)
					bx < rx ? nrx++ : nbx++;
				else if (i == 1)
					bx > rx ? nrx-- : nbx--;
				else if (i == 2)
					by < ry ? nry++ : nby++;
				else
					by > ry ? nry-- : nby--;
			}

			if(dist[nbx][nby][nrx][nry] != -1) continue;
			dist[nbx][nby][nrx][nry] = cnt + 1;
			q.push({nbx, nby, nrx, nry});
		}
	}

	return -1;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	string board[15];
	vector<pair<int, int>> pos(2);
	for (int i = 0; i < N; i++)
	{
		cin >> board[i];
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'R')
			{
				pos[1] = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B')
			{
				pos[0] = { i, j };
				board[i][j] = '.';
			}
		}
	}

	cout << BFS(board, pos);
	return 0;
}