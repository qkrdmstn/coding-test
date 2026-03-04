#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int BFS(vector<vector<int>>& board, int n, int m)
{
	int cnt = 0;
	//방문 표시 및 치즈 위치라면 외부 공기와 맞닿는 면 count
	vector<vector<int>> airCnt(n, vector<int>(m, -1));
	queue<pair<int, int>> q;

	q.push({0,0});
	airCnt[0][0] = 0;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;


			if (board[nx][ny] == 1)
			{
				if(airCnt[nx][ny] < 0) airCnt[nx][ny] = 0;
				airCnt[nx][ny]++;
				continue;
			}

			if(airCnt[nx][ny] >= 0) continue;
			q.push({nx, ny});
			airCnt[nx][ny] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && airCnt[i][j] >= 2)
			{
				cnt++;
				board[i][j] = 0;
			}
		}
	}

	return cnt;
}

int main(void)
{
	int n, m, cnt = 0, ans = 0;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 1) cnt++;
		}
	}

	while (true)
	{
		cnt -= BFS(board, n, m);
		ans++;
		if(cnt <= 0) break;
	}
	cout << ans;
	return 0;
}