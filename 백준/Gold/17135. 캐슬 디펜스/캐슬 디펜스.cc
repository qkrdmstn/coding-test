#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[3] = {0, -1, 0};
int dy[3] = {-1,0,1};

int n, m, d;
vector<vector<int>> board(16, vector<int>(16));
int ans = 0;

int Attack(vector<int>& archerPos, vector<vector<int>>& boardCpy)
{
	int score = 0;
	vector<pair<int, int>> attackPos;
	for (int i = 0; i < 3; i++)
	{
		queue<pair<int, int>> q;
		vector<vector<int>> dist(n + 1, vector<int>(m, -1));

		q.push({ n, archerPos[i] });
		dist[n][archerPos[i]] = 0;

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			if (dist[cur.first][cur.second] > d) continue;
			if (boardCpy[cur.first][cur.second] == 1)
			{
				attackPos.push_back(cur);
				break;
			}

			for (int dir = 0; dir < 3; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (dist[nx][ny] >= 0) continue;
				q.push({ nx, ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}
	}

	for (auto& p : attackPos)
	{
		if (boardCpy[p.first][p.second] == 1)
		{
			score++;
			boardCpy[p.first][p.second] = 0;
		}
	}
	return score;
}

int Move(vector<vector<int>>& boardCpy)
{
	int enemyCount = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if(boardCpy[i][j] == 1) enemyCount++;
			boardCpy[i + 1][j] = boardCpy[i][j];
		}
	}
	for(int i=0; i<m; i++)
		boardCpy[0][i] = 0;
	return enemyCount;
}

int Play(vector<int>& res)
{
	vector<vector<int>> boardCpy = board;

	int score = 0;
	while (true)
	{
		score += Attack(res, boardCpy);
		if(Move(boardCpy) == 0) break;

	}
	return score;
}

void DFS(int st, vector<int>& res)
{
	if (res.size() == 3)
	{
		ans = max(ans, Play(res));
		return;
	}

	for (int i = st; i < m; i++)
	{
		res.push_back(i);
		DFS(i+1, res);
		res.pop_back();
	}
}

int main(void)
{
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for(int j=0; j< m; j++)
			cin >> board[i][j];
	}

	vector<int> res;
	DFS(0, res);
	cout << ans;
	return 0;
}