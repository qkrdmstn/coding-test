#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int l, r, c;
string map[31][31];
int dist[31][31][31];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		queue<tuple<int, int, int>> q;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> map[i][j];
				for (int k = 0; k < c; k++) {
					dist[i][j][k] = -1;
					if (map[i][j][k] == 'S') {
						q.push({ i,j,k });
						dist[i][j][k] = 0;
					}
				}
			}
		}
		
		bool escape = false;
		while (!q.empty() && !escape) {
			tuple<int, int, int> cur = q.front();
			q.pop();

			int curX, curY, curZ;
			tie(curX, curY, curZ) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				int nz = curZ + dz[dir];

				if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c)
					continue;
				if (map[nx][ny][nz] == '#' || dist[nx][ny][nz] != -1)
					continue;
				if (map[nx][ny][nz] == 'E') { //탈출
					escape = true;
					cout << "Escaped in " << dist[curX][curY][curZ] + 1 << " minute(s).\n";
					break;
				}
				q.push({ nx,ny,nz });
				dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			}
		}
		if (!escape)
			cout << "Trapped!\n";
	}

	return 0;
}