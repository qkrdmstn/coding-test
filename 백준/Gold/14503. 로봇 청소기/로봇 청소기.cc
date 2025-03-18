#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c, d;
int map[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;
bool visited[51][51];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	q.push({ r,c });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		visited[cur.first][cur.second] = true;
		//4방향 청소 확인
		bool isClean = true;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (map[nx][ny] == 1 || visited[nx][ny])
				continue;
			isClean = false;
		}

		//후진
		if (isClean) {
			int dir = (d + 2) % 4;
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (map[nx][ny] == 1) {
				break;
			}
			q.push({ nx, ny });
		}
		//반시계 방향으로 90도 회전
		else {
			d = (d + 3) % 4;
			int nx = cur.first + dx[d];
			int ny = cur.second + dy[d];
			//청소 안돼있으면 전진
			if (!visited[nx][ny] && map[nx][ny] != 1) {
				q.push({ nx, ny });
			}
			else
				q.push({ cur.first, cur.second });
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j])
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}