#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				q.push({i, j});
				dist[i][j] = 0;
			}
			else if(board[i][j] == 0)
				dist[i][j] = 0;
		}
	}

	int dx[4] = {0,1,0,-1};
	int dy[4] = {1,0,-1,0};
	while (!q.empty())
	{
		pair<int ,int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
 			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(board[nx][ny] != 1 || dist[nx][ny] >= 0) continue;
			q.push({nx, ny});
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for(int j=0; j<m; j++)
			cout << dist[i][j] << " ";
		cout << "\n";
	}
	return 0;
}