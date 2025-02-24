#include<iostream>
#include<queue>
#include <string>
#include <tuple>
using namespace std;

string map[1001];
int n, m, p;
int s[10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1, 0, 0 };
queue<tuple<int, int, int>> q[10];
int area[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < m; j++) {
			for (int k = 1; k <= p; k++) {
				if (map[i][j] - '0' == k) {
					q[k].push({ i,j,0 });
					area[k]++;
				}
			}
		}
	}

	while (true) {
		bool isExtend = false;
		for (int curP = 1; curP <= p; curP++) {
			queue<tuple<int, int, int>> nextQ;
			while (!q[curP].empty()) {
				int curX, curY, curStep;
				tie(curX, curY, curStep) = q[curP].front();
				q[curP].pop();

				if (curStep >= s[curP]) {
					nextQ.push({ curX, curY, 0 });
					continue;
				}

				for (int dir = 0; dir < 4; dir++) {
					int nx = curX + dx[dir];
					int ny = curY + dy[dir];
					int nStep = curStep + 1;

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (map[nx][ny] != '.')
						continue;

					q[curP].push({nx, ny, nStep});
					map[nx][ny] = map[curX][curY];
					area[curP]++;
					isExtend = true;
				}
			}
			q[curP] = nextQ;
		}
		if (!isExtend)
			break;
	}

	for (int i = 1; i <= p; i++)
		cout << area[i] << " ";
	return 0;
}