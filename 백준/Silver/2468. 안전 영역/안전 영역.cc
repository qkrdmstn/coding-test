#include <iostream>
#include <queue>
using namespace std;

int n; 
int map[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int maxH = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > maxH)
				maxH = map[i][j];
		}
	}
	
	int maxArea = 0;
	for (int h = 0; h <= maxH; h++) { //장마철 내리는 비의 양 전수조사.

		bool visited[101][101] = {};
		queue<pair<int, int>> q;
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] > h && !visited[i][j]) {
					q.push({ i,j });
					visited[i][j] = true;

					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();

						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= n)
								continue;
							if (map[nx][ny] <= h || visited[nx][ny])
								continue;
							q.push({ nx, ny });
							visited[nx][ny] = true;
						}
					}
					area++;
				}
			}
		}
		if (area > maxArea)
			maxArea = area;
	}

	cout << maxArea;
	return 0;
}