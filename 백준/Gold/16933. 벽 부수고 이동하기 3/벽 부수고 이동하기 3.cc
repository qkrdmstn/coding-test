#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int n, m, k;
string board[1005];
int dist[1005][1005][11][2];

int BFS()
{
	queue<tuple<int, int, int, int>> q;

	q.push({ 0,0,k,0 });
	dist[0][0][k][0] = 1;
	while (!q.empty())
	{
		int cx, cy, ck, ct;
		tie(cx, cy, ck, ct) = q.front(); q.pop();

		//목적지 도착
		if (cx == n - 1 && cy == m - 1)
			return dist[cx][cy][ck][ct];

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			int nt = 1 - ct;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			//벽을 부술 수 있는 상태
			if (board[nx][ny] == '1' && ck > 0)
			{
				//낮
				if (ct == 0)
				{
					int nk = ck - 1;
					if (dist[nx][ny][nk][nt] >= 1) continue;
					q.push({ nx, ny, nk, nt });
					dist[nx][ny][nk][nt] = dist[cx][cy][ck][ct] + 1;
				}
				//밤
				else
				{
					//제자리에서 낮을 기다림.
					int nk = ck;
					if (dist[cx][cy][nk][nt] >= 1) continue;
					q.push({ cx, cy, nk, nt });
					dist[cx][cy][nk][nt] = dist[cx][cy][ck][ct] + 1;
				}
			}
			else if (board[nx][ny] == '0')
			{
				int nk = ck;
				if (dist[nx][ny][nk][nt] >= 1) continue;
				q.push({ nx, ny, nk, nt });
				dist[nx][ny][nk][nt] = dist[cx][cy][ck][ct] + 1;
			}
		}
	}
	return -1;
}

int main(void)
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	cout << BFS();
	return 0;
}