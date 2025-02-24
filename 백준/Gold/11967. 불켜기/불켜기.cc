#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
bool light[101][101];
bool visited[101][101];
vector<pair<int, int>> v[101][101]; //스위치
queue<pair<int, int>> q;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int j = 0; j < m; j++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		v[x][y].push_back({ a,b });
	}

	q.push({ 1,1 });
	light[1][1] = true;
	visited[1][1] = true;

	int lightCnt = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur.first][cur.second].size(); i++) { //현재 방에 존재하는 스위치 순회
			pair<int, int> lightPos = v[cur.first][cur.second][i];
			if (!light[lightPos.first][lightPos.second]) { //불 켜기
				light[lightPos.first][lightPos.second] = true;
				lightCnt++;

				//불을 켰으면 모든 방문을 초기화하여 다시 탐색
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						visited[i][j] = false;
					}
				}
			}
		} 

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx <= 0 || nx > n || ny <= 0 || ny > n)
				continue;
			//불이 꺼져있거나 이미 방문했으면 continue;
			if (!light[nx][ny] || visited[nx][ny])
				continue;

			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}

	cout << lightCnt;
	return 0;
}