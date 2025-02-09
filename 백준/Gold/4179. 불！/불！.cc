#include <iostream>
#include <string>
#include <queue>
using namespace std;

int r, c;
string map[1001];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> map[i];
		for (int j = 0; j < c; j++) {
			dist1[i][j] = -1;
			dist2[i][j] = -1;
			if (map[i][j] == 'F') {
				q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (map[i][j] == 'J') {
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty()) { //불에 대한 BFS
		pair<int, int> cur = q1.front();
		q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (map[nx][ny] == '#' || dist1[nx][ny] != -1)
				continue;

			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			q1.push({ nx, ny });
		}
	}

	while (!q2.empty()) { //지훈이에 대한 BFS
		pair<int, int> cur = q2. front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (map[nx][ny] == '#' || dist2[nx][ny] != -1)
				continue;
			if (dist1[nx][ny] != -1 && dist2[cur.first][cur.second] + 1 >= dist1[nx][ny])
				continue;

			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			q2.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}