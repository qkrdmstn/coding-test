#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int n, m, k;
string map[1001];
queue<tuple<int, int, int, int>> q;
int dist[1001][1001][11][2]; //0: 낮, 1: 밤
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0, 0 };

bool IsDay(int curDist)
{
	if (curDist % 2 == 1)
		return true;
	else
		return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	dist[0][0][k][0] = 1;
	q.push({ 0,0,k, 0});

	while (!q.empty()) {
		int curX, curY, curK, curDay;
		tie(curX, curY, curK, curDay) = q.front();
		q.pop();

		if (curX == n - 1 && curY == m - 1) {
			cout << dist[curX][curY][curK][curDay];
			return 0;
		}

		int nDay = 1 - curDay;
		for (int dir = 0; dir < 4; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			//벽을 부수는 경우
			if (map[nx][ny] == '1' && curDay == 0 && curK > 0 && dist[nx][ny][curK - 1][nDay] == 0) {
				int nk = curK - 1;
				dist[nx][ny][nk][nDay] = dist[curX][curY][curK][curDay] + 1;
				q.push({ nx, ny, nk, nDay });
			}
			//벽을 못 부수는 경우
			else if (map[nx][ny] == '1' && curDay == 1 && curK > 0 && dist[nx][ny][curK - 1][nDay] == 0) {
				dist[curX][curY][curK][nDay] = dist[curX][curY][curK][curDay] + 1;
				q.push({ curX, curY, curK, nDay });
			}
			else if (map[nx][ny] == '0' && dist[nx][ny][curK][nDay] == 0) {
				q.push({ nx, ny, curK, nDay });
				dist[nx][ny][curK][nDay] = dist[curX][curY][curK][curDay] + 1;
			}
		}

	}
	cout << -1 << "\n";

	return 0;
}