#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,1,-1};
struct Shark
{
	int s; //속력
	int d; //방향
	int z; //크기
};

void MoveSharks(vector<vector<Shark>>& board, int r, int c)
{
	vector<vector<Shark>> nextBoard(r, vector<Shark>(c, { 0,0,0 }));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int s = board[i][j].s;
			int d = board[i][j].d;
			int z = board[i][j].z;
			if (z == 0) continue;

			//모듈러 연산으로 중복되는 이동거리를 줄입니다.
			int moveCount = s;
			if (d == 0 || d == 1) moveCount %= ((r - 1) * 2);
			else moveCount %= ((c - 1) * 2);

			//나머지만큼 직접 이동 시뮬레이션 합니다.
			int cr = i;
			int cc = j;
			while (moveCount > 0)
			{
				int nr = cr + dr[d];
				int nc = cc + dc[d];

				//범위를 벗어나는 경우 방향을 전환합니다.
				if (nr < 0 || nr >= r || nc < 0 || nc >= c)
				{
					if (d == 0) d = 1;
					else if (d == 1) d = 0;
					else if (d == 2) d = 3;
					else if (d == 3) d = 2;
					nr = cr + dr[d];
					nc = cc + dc[d];
				}
				cr = nr;
				cc = nc;
				moveCount--;
			}

			//한 칸에 두 마리 상어가 있는 경우 더 큰 상어만 남습니다.
			if (z > nextBoard[cr][cc].z)
				nextBoard[cr][cc] = { s, d, z };
		}
	}
	board = nextBoard;
}

int main(void)
{
	int r, c, m;
	cin >> r >> c >> m;

	//{크기, 속력, 방향}
	vector<vector<Shark>> board(r, vector<Shark>(c, {0,0,0}));
	for (int i = 0; i < m; i++)
	{
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		board[x-1][y-1] = {s,d-1,z};
	}

	int ans = 0;
	for(int fisher = 0; fisher < c; fisher++)
	{
		//1. 현재 열의 상어를 잡습니다.
		for (int i = 0; i < r; i++)
		{
			int s = board[i][fisher].s;
			int d = board[i][fisher].d;
			int z = board[i][fisher].z;
			//상어가 없는 위치라면 건너뜁니다.
			if(z == 0) continue;
			ans += z;
			board[i][fisher] = {0,0,0};
			break;
		}

		//2. 상어가 이동합니다.
		MoveSharks(board, r, c);
	}
	cout << ans << "\n";
	return 0;
}