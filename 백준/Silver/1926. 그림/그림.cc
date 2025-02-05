#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int map[501][501] = {};
bool visited[501][501];

int pictureCnt = 0;
int pictureArea = 0;
int maxArea = 0;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (map[i][j] != 1 || visited[i][j]) continue;
			pictureCnt++;
			queue<pair<int, int>> q;
			q.push({ i,j });
			visited[i][j] = true;

			pictureArea = 0;
			while (!q.empty()) {

				pair<int,int> cur = q.front();
				q.pop();
				pictureArea++;
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visited[nx][ny] || map[nx][ny] != 1) continue;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
			if (pictureArea > maxArea) maxArea = pictureArea;
		}
	}
	cout << pictureCnt << "\n";
	cout << maxArea << "\n";
	return 0;
}