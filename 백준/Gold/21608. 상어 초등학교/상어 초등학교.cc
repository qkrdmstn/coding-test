#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n;
typedef tuple<int, int, int, int> info;

vector<vector<int>> likes(401, vector<int>());
vector<int> order(401);
int board[401][401];

bool cmp(info a, info b)
{
	int alike, ablank, ax, ay;
	int blike, bblank, bx, by;
	tie(alike, ablank, ax, ay) = a;
	tie(blike, bblank, bx, by) = b;

	if (alike == blike)
	{
		if (ablank == bblank)
		{
			if (ax == bx)
				return ay < by;
			return ax < bx;
		}
		return ablank > bblank;
	}
	return alike > blike;
}

void func(int curStudent, vector<info>& infos)
{
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= n; y++)
		{
			if (board[x][y] != 0) continue;

			int like = 0, blank = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

				if (board[nx][ny] == 0) blank++;
				else
				{
					for (int l = 0; l < 4; l++)
					{
						if (likes[curStudent][l] == board[nx][ny])
						{
							like++;
							break;
						}
					}
				}
			}
			infos.push_back({ like, blank, x, y });
		}
	}
}

int main(void)
{

	cin >> n;
	for (int i = 1; i <= n * n; i++)
	{
		int num, like;
		cin >> order[i];
		for (int j = 0; j < 4; j++)
		{
			cin >> like;
			likes[order[i]].push_back(like);
		}
	}

	for (int i = 1; i <= n * n; i++)
	{
		int student = order[i];
		vector<info> infos;
		func(student, infos);

		sort(infos.begin(), infos.end(), cmp);
		int like, blank, x, y;
		tie(like, blank, x, y) = infos[0];
		board[x][y] = student;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int curStudent = board[i][j];
			int like = 0;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

				for (int l = 0; l < 4; l++)
				{
					if (likes[curStudent][l] == board[nx][ny])
					{
						like++;
						break;
					}
				}
			}
			if (like == 0) continue;

			int sat = 1;
			for (int k = 1; k < like; k++) 
				sat *= 10;
			ans += sat;
		}
	}

	cout << ans;
	return 0;
}