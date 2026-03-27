#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int r, c, k, w;
int board[25][25];
bool wall[25][25][4] = { false };

//방향: 우좌상하
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct Machine
{
	int x, y, dir;
};

vector<Machine> machines;
vector<pair<int, int>> targets;

void Blow(Machine m)
{
	bool vis[25][25] = { false };
	queue<tuple<int, int, int>> q;

	int nx = m.x + dx[m.dir];
	int ny = m.y + dy[m.dir];
	if (nx < 1 || nx > r || ny < 1 || ny > c) return;

	q.push({ nx, ny, 5 });
	vis[nx][ny] = true;

	while (!q.empty())
	{
		int cx, cy, tmp;
		tie(cx, cy, tmp) = q.front(); q.pop();

		board[cx][cy] += tmp;
		if (tmp == 1) continue;

		int nx1 = cx + dx[m.dir];
		int ny1 = cy + dy[m.dir];
		if (nx1 >= 1 && nx1 <= r && ny1 >= 1 && ny1 <= c && !vis[nx1][ny1])
		{
			if (!wall[cx][cy][m.dir])
			{
				vis[nx1][ny1] = true;
				q.push({ nx1, ny1, tmp - 1 });
			}
		}

		int sideDirs[2];
		if (m.dir == 0 || m.dir == 1) { sideDirs[0] = 2; sideDirs[1] = 3; }
		else { sideDirs[0] = 0; sideDirs[1] = 1; }

		for (int i = 0; i < 2; i++)
		{
			int sDir = sideDirs[i];

			int mx = cx + dx[sDir];
			int my = cy + dy[sDir];

			int nx2 = mx + dx[m.dir];
			int ny2 = my + dy[m.dir];

			if (nx2 >= 1 && nx2 <= r && ny2 >= 1 && ny2 <= c && !vis[nx2][ny2])
			{
				if (!wall[cx][cy][sDir] && !wall[mx][my][m.dir])
				{
					vis[nx2][ny2] = true;
					q.push({ nx2, ny2, tmp - 1 });
				}
			}
		}
	}
}

void Adjust()
{
	int nxtBoard[25][25] = {0};

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int nx = i + dx[d];
				int ny = j + dy[d];

				if (nx >= 1 && nx <= r && ny >= 1 && ny <= c)
				{
					if (!wall[i][j][d] && board[i][j] > board[nx][ny])
					{
						int diff = (board[i][j] - board[nx][ny]) / 4;
						nxtBoard[i][j] -= diff;
						nxtBoard[nx][ny] += diff;
					}
				}
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			board[i][j] += nxtBoard[i][j];
		}
	}
}

void DecreaseEdge() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (i == 1 || i == r || j == 1 || j == c) {
				if (board[i][j] > 0) board[i][j]--;
			}
		}
	}
}

bool CheckTargets() {
	for (auto t : targets) {
		if (board[t.first][t.second] < k) return false;
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
			int val; cin >> val;
			if (val >= 1 && val <= 4)
				machines.push_back({ i, j, val - 1 });
			else if (val == 5)
				targets.push_back({ i, j });
		}
	}

	cin >> w;
	for (int i = 0; i < w; i++)
	{
		int x, y, t; cin >> x >> y >> t;
		if (t == 0)
		{
			wall[x][y][2] = true;
			wall[x - 1][y][3] = true;
		}
		else
		{
			wall[x][y][0] = true;
			wall[x][y + 1][1] = true;
		}
	}

	int ans = 0;
	while (ans <= 100) {
		for (auto m : machines) Blow(m);
		Adjust();
		DecreaseEdge();
		ans++;
		if (CheckTargets()) break;
	}

	if (ans > 100) cout << 101 << "\n";
	else cout << ans << "\n";

	return 0;
}
