#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'I')
			{
				visited[i][j] = true;
				q.push({i, j});
			}
		}
	}

	int answer = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		if(board[cur.first][cur.second] == 'P')
			answer++;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx < 0 || nx>=n || ny < 0 || ny >= m) continue;
			if(board[nx][ny] == 'X' || visited[nx][ny]) continue;
			q.push({nx, ny});
			visited[nx][ny] = true;
		}
	}
	if(answer)
		cout << answer;
	else cout << "TT";
	return 0;
}