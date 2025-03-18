#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, ans;
int map[8][8];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> virus;
vector<pair<int, int>> blank;

int VirusSimulation()
{
	queue<pair<int, int>> q;
	bool visited[8][8] = {};
	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first, virus[i].second });
		visited[virus[i].first][virus[i].second] = true;
	}

	int ret = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		ret++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visited[nx][ny] || map[nx][ny] != 0)
				continue;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0)
				blank.push_back({ i,j });
			if (map[i][j] == 2)
				virus.push_back({ i,j });
		}
	}

	for (int i = 0; i < blank.size(); i++) {
		map[blank[i].first][blank[i].second] = 1;
		for (int j = i + 1; j < blank.size(); j++) {
			map[blank[j].first][blank[j].second] = 1;
			for (int k = j + 1; k < blank.size(); k++) {
				map[blank[k].first][blank[k].second] = 1;
				int tmp = VirusSimulation();
				ans = max(ans, (int)blank.size() - 3 - tmp + (int)virus.size());
				map[blank[k].first][blank[k].second] = 0;
			}
			map[blank[j].first][blank[j].second] = 0;
		}
		map[blank[i].first][blank[i].second] = 0;
	}

	cout << ans;
	return 0;
}