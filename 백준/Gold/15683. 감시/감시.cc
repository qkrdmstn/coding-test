#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
int ans;
int map[10][10];
int dx[4] = { 1,0,-1,0 }; //동, 남, 서, 북
int dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> cctvPos;

int blankCount()
{
	int blank = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				blank++;
		}
	}
	return blank;
}

bool OOB(int x, int y)
{
	return (x < 0 || x >= n || y < 0 || y >= m);
}

void cctvOversight(int x, int y, int dir)
{
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (map[x][y] == 6 || OOB(x, y))
			break;
		if (map[x][y] != 0)
			continue;

		map[x][y] = 7;
	}
}

void func(int cctvIdx)
{
	if (cctvIdx == cctvPos.size()) {
		ans = min(blankCount(), ans);
		return;
	}
	else {
		int backUp[10][10];
		for (int dir = 0; dir < 4; dir++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					backUp[i][j] = map[i][j];
				}
			}

			int x, y, cctvKind;
			tie(x, y) = cctvPos[cctvIdx];
			cctvKind = map[x][y];

			if (cctvKind == 1) {
				cctvOversight(x, y, dir);

			}
			else if (cctvKind == 2) {
				cctvOversight(x, y, dir);
				cctvOversight(x, y, dir + 2);
			}
			else if (cctvKind == 3) {
				cctvOversight(x, y, dir);
				cctvOversight(x, y, dir + 1);
			}
			else if (cctvKind == 4) {
				cctvOversight(x, y, dir);
				cctvOversight(x, y, dir + 1);
				cctvOversight(x, y, dir + 3);
			}
			else if (cctvKind == 5) {
				cctvOversight(x, y, dir);
				cctvOversight(x, y, dir + 1);
				cctvOversight(x, y, dir + 2);
				cctvOversight(x, y, dir + 3);
			}

			func(cctvIdx + 1);

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					map[i][j] = backUp[i][j];
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				cctvPos.push_back({ i, j });
			else if (map[i][j] == 0)
				ans++;
		}
	}

	func(0);
	cout << ans;
	return 0;

	/*두 가지 풀이법
	1. 백 트래킹을 활용한 풀이: 간단하게 모든 cctv에 대해 4방향 감시를 모두 탐색하도록 백트래킹을 수행
	-> 이 방법은 백트래킹 방법이기 때문에 탐색이 끝났으면 직전 상태로 맵을 되돌려야 한다.

	2. 4진법을 활용한 풀이: (1<<(2*cctv.size())) 연산을 활용해서 cctv개수 * 2 만큼의 bit를 생성하고, 각각 비트에 의해 감시를 수행
	-> 이 방법은 각 경우의 수가 독립적으로 수행되기 때문에 한 번의 연산마다 맵을 처음 상태로 초기화 해주면 된다.
	*/
}