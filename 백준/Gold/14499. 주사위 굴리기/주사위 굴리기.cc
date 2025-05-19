#include <iostream>
#include <deque>
using namespace std;

int n, m, x, y, k;

//0: 전개도 가로줄, 1: 전개도 세로줄
deque<int> dice[2];
int map[21][21];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void RotateDice(int dir)
{
	//1: 동, 2: 서, 3: 북, 4: 남
	if (dir == 1) {
		dice[0].push_front(dice[0].back());
		dice[0].pop_back();
		dice[1][1] = dice[0][1];
		dice[1][3] = dice[0][3];
	}
	else if (dir == 2) {
		dice[0].push_back(dice[0].front());
		dice[0].pop_front();
		dice[1][1] = dice[0][1];
		dice[1][3] = dice[0][3];
	}
	else if (dir == 3) {
		dice[1].push_back(dice[1].front());
		dice[1].pop_front();
		dice[0][1] = dice[1][1];
		dice[0][3] = dice[1][3];
	}
	else if (dir == 4) {
		dice[1].push_front(dice[1].back());
		dice[1].pop_back();
		dice[0][1] = dice[1][1];
		dice[0][3] = dice[1][3];
	}

	//칸에 대한 숫자 처리
	if (map[x][y] == 0) {
		map[x][y] = dice[0][3];
	}
	else {
		for (int i = 0; i < 2; i++)
			dice[i][3] = map[x][y];
		map[x][y] = 0;
	}

	//윗면 출력
	cout << dice[0][1] << '\n';
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	//주사위 전개도 초기화
	for (int i = 0; i < 4; i++) {
		dice[0].push_back(0);
		dice[1].push_back(0);
	}

	while (k--) {
		int dir;
		cin >> dir;

		int nx = x + dx[dir - 1];
		int ny = y - dy[dir - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		x = nx;
		y = ny;
		RotateDice(dir);
	}
	return 0;
}