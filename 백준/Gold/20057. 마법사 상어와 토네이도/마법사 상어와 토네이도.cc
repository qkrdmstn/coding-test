#include <queue>
#include <iostream>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int ratio[12] = { 1, 0, 1, 2, 7, 0, 7, 2, 10, 0, 10, 5 };

//모래 비율별로 나누기
int Wind(int x, int y, int targetX, int targetY, int dir, vector<vector<int>>& board, int n)
{
	int sDir;
	//이동 방향의 수직 방향 설정
	if (dir == 0 || dir == 2) { sDir = 1; }
	else { sDir= 0; }

	int ratioIdx = 0;
	int sideDist[4] = { 1,2,1,0 };
	int cx = x, cy = y;

	int totalSand = board[targetX][targetY];
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int k = -sideDist[i]; k <= sideDist[i]; k++)
		{
			int nx = cx + dx[sDir] * k;
			int ny = cy + dy[sDir] * k;

			//바깥으로 나간 모래
			int ratioSand = (totalSand * ratio[ratioIdx]) / 100;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				ans += ratioSand;
			else
				board[nx][ny] += ratioSand;
			board[targetX][targetY] -= ratioSand;
			ratioIdx++;
		}
		//이동방향 전진
		cx += dx[dir];
		cy += dy[dir];
	}

	//바깥으로 나간 모래
	int aX = targetX + dx[dir], aY = targetY + dy[dir];
	if (aX < 0 || aX >= n || aY < 0 || aY >= n)
		ans += board[targetX][targetY];
	else
		board[aX][aY] += board[targetX][targetY];
	board[targetX][targetY] = 0;
	return ans;
}

//토네이도 움직임
void Move(int x, int y, vector<vector<int>>& board, int n, int& ans)
{
	int dir = 0;
	int dist = 1;

	int cx = x, cy = y;
	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < dist; j++)
			{
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) return;
				ans += Wind(cx, cy, nx, ny, dir, board, n);
				cx = nx;
				cy = ny;
			}
			dir++;
			dir%=4;
		}
		dist++;
	}
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
	Move(n / 2, n / 2, board, n, ans);
	cout << ans;
	return 0;
}