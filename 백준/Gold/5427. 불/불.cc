#include <iostream>
#include <queue>
#include <string>
using namespace std;

int t;
int w, h;
string map[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;

		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			cin >> map[i];
			for (int j = 0; j < w; j++) {
				dist1[i][j] = -1;
				dist2[i][j] = -1;
				if (map[i][j] == '*') {
					q1.push({ i,j });
					dist1[i][j] = 0;
				}
				else if (map[i][j] == '@') {
					q2.push({ i,j });
					dist2[i][j] = 0;
				}
			}
		}

		//불에 대한 BFS
		while (!q1.empty()) {
			auto cur = q1.front();
			q1.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (map[nx][ny] == '#' || dist1[nx][ny] != -1)
					continue;

				dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
				q1.push({ nx, ny });
			}
		}

		//상근이에 대한 BFS
		bool isEscape = false;
		int escapeTime = 0;
		while (!q2.empty() && !isEscape) {
			auto cur = q2.front();
			q2.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) { //탈출
					isEscape = true;
					escapeTime = dist2[cur.first][cur.second] + 1;
					break;
				}
				if (map[nx][ny] == '#' || dist2[nx][ny] != -1) //지나갈 수 없는 길
					continue;
				if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.first][cur.second] + 1) //불이 나보다 먼저 도착한 경우
					continue;

				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
				q2.push({ nx, ny });
			}
		}
		if (isEscape)
			cout << escapeTime << "\n";
		else
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}