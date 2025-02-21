#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<pair<int, int>> q;
int map[301][301];
bool visited[301][301] = {};
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int year = 0;
int cnt = 1;

void InitVisited()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

void AfterYear() //1년 후의 빙산 모습
{
	InitVisited();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && !visited[i][j]) {
				visited[i][j] = true;
				q.push({ i, j });

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (visited[nx][ny])
							continue;
						if (map[nx][ny] == 0) {
							map[cur.first][cur.second]--;
							if (map[cur.first][cur.second] < 0)
								map[cur.first][cur.second] = 0;
							continue;
						}

						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
}

//빙산 개수 count
int CountIceberg()
{
	int count = 0;
	InitVisited();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0 && !visited[i][j]) {
				visited[i][j] = true;
				q.push({ i, j });
				count++;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;
						if (map[nx][ny] == 0 || visited[nx][ny])
							continue;

						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
	}

	return count;
}

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

	while (cnt < 2 && cnt != 0) {
		AfterYear();
		cnt = CountIceberg();
		year++;
	}
	if (cnt == 0)
		cout << 0;
	else
		cout << year;



	return 0;
}