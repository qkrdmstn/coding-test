#include<iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

int dx[4] = { 1,0,-1,0};
int dy[4] = { 0,1,0,-1};
string board[1000];
int dist[1000][1000][11][2] = { -1, };

int BFS(int n, int m, int k)
{
	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int l = 0; l <= k; l++)
				fill(dist[i][j][l], dist[i][j][l] + 2, -1);

	q.push({ 0,0,k,0 });
	dist[0][0][k][0] = 1;
	while (!q.empty())
	{
		int cx, cy, ck, cd;
		tie(cx, cy, ck, cd) = q.front(); q.pop();

		if(cx == n-1 && cy == m-1) return dist[cx][cy][ck][cd];

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int nd = 1 - cd;
			if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;

			if (board[nx][ny] == '1' && ck > 0)
			{
				if (cd == 0)
				{
					int nk = ck - 1;
					if (dist[nx][ny][nk][nd] >= 0) continue;
					q.push({ nx, ny, nk, nd });
					dist[nx][ny][nk][nd] = dist[cx][cy][ck][cd] + 1;
				}
				else
				{
					if (dist[cx][cy][ck][nd] >= 0) continue;
					q.push({ cx, cy, ck, nd });
					dist[cx][cy][ck][nd] = dist[cx][cy][ck][cd] + 1;
				}
			}
			else if (board[nx][ny] == '0')
			{
				if(dist[nx][ny][ck][nd] >= 0) continue;
				q.push({nx, ny, ck, nd});
				dist[nx][ny][ck][nd] = dist[cx][cy][ck][cd] + 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	int n, m, k;

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> board[i];

	cout << BFS(n, m, k);
	return 0;
}