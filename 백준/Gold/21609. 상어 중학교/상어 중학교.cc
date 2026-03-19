#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct Group
{
	int rainbowNum = 0;
	pair<int, int> pivot;
	vector<pair<int, int>> blocks;
	bool operator < (const Group& b) const
	{
		if (blocks.size() == b.blocks.size())
		{
			if (rainbowNum == b.rainbowNum)
			{
				if (pivot.first == b.pivot.first)
					return pivot.second > b.pivot.second;
				return pivot.first > b.pivot.first;
			}
			return rainbowNum > b.rainbowNum;
		}
		return blocks.size() > b.blocks.size();
	}
};

void FindGroups(vector<Group>& groups, vector<vector<int>>& board, int n)
{

	vector<vector<bool>> vis(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] <= 0 || vis[i][j]) continue;

			vector<vector<bool>> zeroVis(n, vector<bool>(n, false));
			queue<pair<int, int>> q;
			q.push({ i, j });
			vis[i][j] = true;

			Group g;
			g.pivot = { i, j };
			int pivotBlock = board[i][j];

			while (!q.empty())
			{
				auto cur = q.front(); q.pop();

				//그룹 정보 업데이트
				if (board[cur.first][cur.second] == 0)
					g.rainbowNum++;
				g.blocks.push_back({ cur.first, cur.second });

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] < -1) continue;
					if (board[nx][ny] == -1 || vis[nx][ny]) continue;
					if (board[nx][ny] == 0 && zeroVis[nx][ny]) continue;
					if (board[nx][ny] != 0 && board[nx][ny] != pivotBlock) continue;

					q.push({ nx, ny });
					if (board[nx][ny] == 0)
						zeroVis[nx][ny] = true;
					else
						vis[nx][ny] = true;
				}
			}
			if(g.blocks.size() > 1)
				groups.push_back(g);
		}
	}
}

void Gravity(vector<vector<int>>& board, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] < 0) continue;
			int curNum = board[i][j];
			int cx = i;
			while (cx + 1 <= n - 1 && board[cx + 1][j] == -10)
				cx += 1;
			board[i][j] = -10;
			board[cx][j] = curNum;
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

	int score = 0;
	while (true)
	{
		vector<Group> groups;
		FindGroups(groups, board, n);
		if (groups.empty()) break;

		sort(groups.begin(), groups.end());
		score += groups[0].blocks.size() * groups[0].blocks.size();
		for (auto& b : groups[0].blocks)
			board[b.first][b.second] = -10;

		Gravity(board, n);
		Rotate(board, n);
		Gravity(board, n);
	}
	cout << score;
	return 0;
}