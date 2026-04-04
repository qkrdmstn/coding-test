#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int r[12] = { 1,0,1,2,7,0,7,2,10,0,10,5 };
int d[4] = {1, 2, 1, 0};

bool IsBounded(int x, int y, int n)
{
	if (x < 0 || x >= n || y < 0 || y >= n) return false;
	return true;
}

int wind(int x, int y, int dir, vector<vector<int>>& board, int n)
{
	int sideDir;
	if(dir == 0 || dir == 2) sideDir = 1;
	else sideDir = 0;

	int nx = x + dx[dir], ny = y +dy[dir];
	if (!IsBounded(nx, ny, n)) return 0;
	int totalSand = board[nx][ny];

	int outOfSand = 0;
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = -d[i]; j <= d[i]; j++)
		{
			int sand = totalSand * r[idx] / 100;
			int cx = x + dx[sideDir] * j;
			int cy = y + dy[sideDir] * j;

			if(!IsBounded(cx,cy,n)) outOfSand += sand;
			else board[cx][cy] += sand;
			board[nx][ny] -= sand;
			idx++;
		}

		x += dx[dir];
		y += dy[dir];
	}

	int ax = nx + dx[dir], ay = ny + dy[dir];
	if (!IsBounded(ax, ay, n)) outOfSand += board[nx][ny];
	else board[ax][ay] += board[nx][ny];
	return outOfSand;
}

int main(void)
{
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}

	int ans = 0;
	int cx = n / 2, cy = n / 2;
	int dir = 0;
	int dist = 1;
	while (cy >= 0 && cx >= 0)
	{
		if(cx == 0 && cy == 0) break;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < dist; j++)
			{
				ans += wind(cx, cy, dir, board, n);
				cx += dx[dir], cy += dy[dir];
			}
			dir = (dir + 1) % 4;
		}
		dist++;
	}

	cout << ans;
	return 0;
}