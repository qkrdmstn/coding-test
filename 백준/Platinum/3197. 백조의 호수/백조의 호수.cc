#include <iostream>
#include <queue>
#include <string>
using namespace std;

int r, c, ans;
bool isMeet;
string map[1501];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
queue<pair<int, int>> q3;
queue<pair<int, int>> q4;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
bool visited1[1501][1501];
bool visited2[1501][1501];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	bool flag = false;
	for (int i = 0; i < r; i++) {
		cin >> map[i];

		for (int j = 0; j < c; j++) {
			if (map[i][j] != 'X') { //물인 공간을 q1에 push
				q1.push({ i, j });
				visited1[i][j] = true;
			}
			if (map[i][j] == 'L' && !flag) {
				q3.push({ i, j });
				visited2[i][j] = true;
				flag = true;
			}
		}
	}

	while (!isMeet) {
		//현재 위치에서 주변에 빙판이 있으면 q2에 push
		while (!q1.empty()) {
			pair<int, int> cur = q1.front();
			q1.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				if (visited1[nx][ny])
					continue;

				if (map[nx][ny] == 'X')
					q2.push({nx, ny});
				visited1[nx][ny] = true;
			}
		}

		while (!q2.empty()) { //q2에 있는 공간을 물로 변경한 뒤 그곳을 다시 q1에 push
			pair<int, int> cur = q2.front();
			q2.pop();
			map[cur.first][cur.second] = '.';
			q1.push({ cur.first, cur.second });
		}


		ans++;
		
		while (!q3.empty()) {
			pair<int, int> cur = q3.front();
			q3.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dir[dx];
				int ny = cur.second + dir[dy];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				if (visited2[nx][ny])
					continue;

				if (map[nx][ny] == 'X') {
					q4.push({ nx, ny });
					visited2[nx][ny] = true;
					continue;
				}
				else if (map[nx][ny] == 'L') {
					isMeet = true;
					break;
				}
				q3.push({ nx, ny });
				visited2[nx][ny] = true;
			}
		}

		while (!q4.empty()) {
			pair<int, int> cur = q4.front();
			q4.pop();
			q3.push({ cur.first, cur.second });
		}
	}

	cout << ans;

	/*
	BFS 최적화 문제.
	첫 번째 접근 방식) 매일 모든 빙판의 가장자리를 찾아 녹인 뒤(O(R*C)), 이때 백조가 만날 수 있는지 확인(O(R*C))하는 로직을 설계하면 
	O(R*C*R*C)로 1500^4 으로 1초 시간제한 내에 해결하지 못한다. 

	최적화 접근 방식) 크게 두 가지 로직으로 나누어 생각할 수 있다.
	1. 빙판을 녹이는 작업: 이는 처음 한 번만 물과 닿아있는 빙판을 찾은 뒤, 이후엔 새로 생긴 물, 즉 어제 녹은 빙판의 주위에 있는 현재 빙판만 찾는 방식이다.
	2. 백조가 만날 수 있는지 확인: 매번 하나의 백조에서 시작하여 탐색하는 것이 아닌, 빙판에 의해 막혔을 경우 내일은 해당 빙판이 녹을 가능성이 있기 때문에
	다음날에 다시 해당 빙판부터 탐색을 시작하면 된다.

	위의 두 가지 로직의 최적화를 통해 시간 제한 내에 풀 수 있는 O(RC + RC) 시간 복잡도를 가지게 된다.
	*/
	return 0;
}