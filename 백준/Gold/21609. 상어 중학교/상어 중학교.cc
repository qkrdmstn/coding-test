#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void Gravity(vector<vector<int>>& board, int n)
{
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] < 0) continue;
			int nx = i;
			while (nx < n - 1 && board[nx + 1][j] == -10)
				nx += 1;

			if (nx != i)
			{
				board[nx][j] = board[i][j];
				board[i][j] = -10;
			}
		}
	}
}

void Rotate(vector<vector<int>>& board, int n)
{
	vector<vector<int>> nxtBoard(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			nxtBoard[n - 1 - j][i] = board[i][j];
	}
	board = nxtBoard;
}

bool CheckMaxGroup(int maxSize, int maxRainbowNum, pair<int, int> maxGroupPivot, int curSize, int curRainbowNum, pair<int, int> curPivot)
{
	if (maxSize == curSize)
	{
		if (maxRainbowNum == curRainbowNum)
		{
			if (maxGroupPivot.first == curPivot.first)
			{
				if (maxGroupPivot.second < curPivot.second)
					return true;
			}
			else if(maxGroupPivot.first < curPivot.first)
				return true;
		}
		else if(maxRainbowNum < curRainbowNum)
			return true;
	}
	else if(maxSize < curSize)
		return true;

	return false;
}

int BFS(vector<vector<int>>& board, int n)
{
	int maxSize = 0;
	int maxRainbowNum = 0;
	pair<int, int> maxGroupPivot;

	//가장 큰 그룹 찾기
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j] || board[i][j] <= 0) continue;
			vector<vector<bool>> rainbowVis(n, vector<bool>(n, false));

			queue<pair<int, int>> q;
			vis[i][j] = true;
			q.push({ i, j });
			int curNum = board[i][j];
			int curSize = 0;
			int curRainbowNum = 0;

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();

				curSize++;
				if(board[cur.first][cur.second] == 0) curRainbowNum++;

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if(board[nx][ny] < 0) continue;
					if(vis[nx][ny] || rainbowVis[nx][ny]) continue;

					if (board[nx][ny] == curNum)
					{
						vis[nx][ny] = true;
						q.push({ nx, ny });
					}
					else if (board[nx][ny] == 0)
					{
						rainbowVis[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}
			if (CheckMaxGroup(maxSize, maxRainbowNum, maxGroupPivot, curSize, curRainbowNum, { i, j }))
			{
				maxSize = curSize;
				maxRainbowNum = curRainbowNum;
				maxGroupPivot = { i, j };
			}
		}
	}
	if(maxSize < 2) return 0;

	//최대 그룹 지우기
	vector<vector<bool>> vis2(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	vis2[maxGroupPivot.first][maxGroupPivot.second] = true;
	q.push({ maxGroupPivot.first, maxGroupPivot.second });
	int curNum = board[maxGroupPivot.first][maxGroupPivot.second];
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		board[cur.first][cur.second] = -10;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] < 0) continue;
			if (vis2[nx][ny]) continue;

			if (board[nx][ny] == curNum || board[nx][ny] == 0)
			{
				vis2[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return maxSize * maxSize;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	int ans = 0;
	while (true)
	{
		int res = BFS(board, n);
		if(res == 0) break;
		ans += res;
		Gravity(board, n);
		Rotate(board, n);
		Gravity(board, n);
	}
	cout << ans;
	return 0;
}