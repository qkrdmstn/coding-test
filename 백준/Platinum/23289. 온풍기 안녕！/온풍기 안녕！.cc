#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Machine
{
	int x, y, dir;
};
int r, c, k;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int board[25][25];
bool isWall[25][25][4];
vector<Machine> m;
vector<pair<int, int>> pos;

void BFS(Machine m)
{
	queue<pair<int, int>> q;
	int dist[25][25];
	for (int i = 1; i <= r; i++)
		fill(dist[i], dist[i] + c + 1, -1);

	int cx = m.x + dx[m.dir];
	int cy = m.y + dy[m.dir];
	q.push({ cx, cy });
	dist[cx][cy] = 0;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();

		if (dist[cur.first][cur.second] >= 5) continue;
		else board[cur.first][cur.second] += 5 - dist[cur.first][cur.second];

		int nx1 = cur.first + dx[m.dir], ny1 = cur.second + dy[m.dir];
		if (nx1 >= 1 && nx1 <= r && ny1 >= 1 && ny1 <= c && dist[nx1][ny1] < 0)
		{
			if (!isWall[cur.first][cur.second][m.dir])
			{
				q.push({nx1, ny1});
				dist[nx1][ny1] = dist[cur.first][cur.second] + 1;
			}
		}

		int sideDir[2];
		if(m.dir <= 1) { sideDir[0] = 2, sideDir[1] = 3; }
		else { sideDir[0] = 0, sideDir[1] = 1; }
		for (int i = 0; i < 2; i++)
		{
			int sDir = sideDir[i];
			int mx = cur.first + dx[sDir];
			int my = cur.second + dy[sDir];

			int nx2 = mx + dx[m.dir];
			int ny2 = my + dy[m.dir];

			if(nx2 < 1 || nx2 > r || ny2 < 1 || ny2 > c) continue;
			if(dist[nx2][ny2] >= 0) continue;
			if(isWall[cur.first][cur.second][sDir] || isWall[mx][my][m.dir]) continue;

			q.push({nx2, ny2});
			dist[nx2][ny2] = dist[cur.first][cur.second] + 1;
		}
	}
}

void Adjust()
{
	int nxtBoard[25][25] = { 0, };
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir], ny = j + dy[dir];
				if(nx < 1 || nx > r || ny < 1  || ny > c) continue;
				if (!isWall[i][j][dir] && board[i][j] > board[nx][ny])
				{
					int diff = board[i][j] - board[nx][ny];
					nxtBoard[nx][ny] += diff/4;
					nxtBoard[i][j] -= diff/4;
				}
			}
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			board[i][j] += nxtBoard[i][j];
	}
}

void Edge()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (i == 1 || i == r || j == 1 || j == c)
			{
				if(board[i][j] >= 1)
					board[i][j]--;
			}
		}
	}
}

bool Check()
{
	for (auto& p : pos)
	{
		if(board[p.first][p.second] < k) return false;
	}
	return true;
}

int main(void)
{
	cin >> r >> c >> k;

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 4)
				m.push_back({ i, j, board[i][j] - 1 });
			else if (board[i][j] == 5)
				pos.push_back({ i, j });
			board[i][j] = 0;
		}
	}

	int w;
	cin >> w;
	for (int i = 0; i < w; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		if (t == 0)
		{
			isWall[x][y][2] = true;
			isWall[x-1][y][3] = true;
		}
		else
		{
			isWall[x][y][0] = true;
			isWall[x][y+1][1] = true;
		}
	}

	int turn = 0;
	while (turn <= 100)
	{
		for(auto &machine: m)
			BFS(machine);

		Adjust();
		Edge();
		turn++;
		if(Check()) break;
	}
	cout << turn;
}