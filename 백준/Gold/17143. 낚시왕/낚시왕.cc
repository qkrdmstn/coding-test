#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0,0,1,-1};

struct shark
{
	int s;
	int d;
	int z;
};

void MoveSharks(vector<vector<shark>>& board, int R, int C)
{
	vector<vector<shark>> nxtBoard(R, vector<shark>(C, {0,0,0}));
	for (int i=0; i<R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if(board[i][j].z == 0) continue;

			shark& sh = board[i][j];
			int dist = 0;
			//수직 이동인 경우
			if (sh.d <= 1) dist = sh.s % (2 * (R - 1));
			//수평 이동인 경우
			else dist = sh.s % (2 * (C - 1));

			int x = i, y = j;
			int dir = sh.d;
			while (dist--)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				{
					if (dir == 0) dir = 1;
					else if (dir == 1) dir = 0;
					else if (dir == 2) dir = 3;
					else if (dir == 3) dir = 2;
					nx = x + dx[dir];
					ny = y + dy[dir];
				}
				x = nx;
				y = ny;
				sh.d = dir;
			}
			if(sh.z > nxtBoard[x][y].z)
				nxtBoard[x][y] = sh;

		}
	}
	board = nxtBoard;
}

int main(void)
{
	int R, C, M;
	cin >> R >> C >> M;
	vector<vector<shark>> board(R, vector<shark>(C, {0,0,0}));

	for (int i = 0; i < M; i++)
	{
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		board[x - 1][y - 1] = {s, d-1, z};
	}

	int ans = 0;
	for (int fisher = 0; fisher < C; fisher++)
	{
		//1. 상어 잡기
		for (int i = 0; i < R; i++)
		{
			if(board[i][fisher].z == 0) continue;
			ans += board[i][fisher].z;
			board[i][fisher].z = 0;
			break;
		}

		MoveSharks(board, R, C);
	}
	cout << ans;
	return 0;
}