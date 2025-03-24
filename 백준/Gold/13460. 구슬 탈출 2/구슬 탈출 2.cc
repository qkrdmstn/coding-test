#include <iostream>
#include <string>
using namespace std;

int n, m;
string board[10];
pair<int, int> bluePos, redPos;
pair<int, int> bluePosCpy, redPosCpy;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0,0,-1,1 };
int ans = 11;

int tilt(int dir)
{
	int n_bx = bluePosCpy.first, n_by = bluePosCpy.second, n_rx = redPosCpy.first, n_ry = redPosCpy.second;

	while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.') {
		n_bx += dx[dir];
		n_by += dy[dir];
	}
	if (board[n_bx + dx[dir]][n_by + dy[dir]] == 'O')
		return -1;

	while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.') {
		n_rx += dx[dir];
		n_ry += dy[dir];
	}

	if (board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O')
		return 1;

	if ((n_bx == n_rx) && (n_by == n_ry)) {
		if (dir == 0)
			redPosCpy.first < bluePosCpy.first ? n_bx++ : n_rx++;
		else if (dir == 1)
			redPosCpy.first > bluePosCpy.first ? n_bx-- : n_rx--;
		else if (dir == 2)
			redPosCpy.second < bluePosCpy.second ? n_by++ : n_ry++;
		else
			redPosCpy.second > bluePosCpy.second ? n_by-- : n_ry--;
	}
	redPosCpy = { n_rx, n_ry };
	bluePosCpy = { n_bx, n_by };
	return 0;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'R') {
				redPos = { i,j };
				board[i][j] = '.';
			}
			if (board[i][j] == 'B') {
				bluePos = { i, j };
				board[i][j] = '.';
			}
		}
	}

	////모든 경우의 수 순회
	for (int tmp = 0; tmp < (1 << 2 * 10); tmp++) {
		int brute = tmp;

		redPosCpy = redPos;
		bluePosCpy = bluePos;

		for (int i = 0; i < 10; i++) {
			int dir = brute % 4;
			brute /= 4;
			//성공했으면, 현재 기울인 횟수 check
			int result = tilt(dir);
			//파란 구슬이 빠진 경우
			if (result == -1)
				break;
			else if (result == 1) {
				ans = min(i+1, ans);
				break;
			}
		}
	}
	if (ans == 11)
		cout << -1;
	else
		cout << ans;

	return 0;
}