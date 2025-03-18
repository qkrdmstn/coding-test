#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int n, k, l;
int x, y, dir, t;
//0: 빈칸,  1: 뱀, 2: 사과
int board[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1, 0};
deque<pair<int, int>> snake;
queue<pair<int, char>> rot;

bool Go()
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= n)
		return false;
	if (board[nx][ny] == 1)
		return false;

	snake.push_front({ nx, ny });
	if (board[nx][ny] == 0) {
		board[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	board[nx][ny] = 1;
	x = nx;
	y = ny;
	return true;
}

void Rotate(char c)
{
	if (c == 'L')
		dir += 3;
	else if (c == 'D')
		dir++;
	dir %= 4;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	snake.push_back({ 0,0 });
	board[0][0] = 1;
	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 2;
	}

	cin >> l;
	while (l--) {
		int x;
		char c;
		cin >> x >> c;
		rot.push({ x, c });
	}

	while (Go()) {
		t++;

		if (!rot.empty() && rot.front().first == t) {
			Rotate(rot.front().second);
			rot.pop();
		}
	}
	cout << t+1;
	return 0;
}