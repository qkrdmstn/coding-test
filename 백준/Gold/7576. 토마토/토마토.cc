#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int main(void)
{
	int m, n;
	cin >> m >> n;

	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push({ i, j });
				dist[i][j] = 0;
			} 
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(dist[nx][ny] >= 0 || board[nx][ny] == -1) continue;

			q.push({nx, ny});
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	cout << ans;
	return 0;
}