#include <iostream>
using namespace std;

int n, m, ans, sum;
int map[501][501];
bool visited[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void DFS(int x, int y, int depth)
{
	if (depth == 4) {
		ans = max(ans, sum);
		return;
	}
	else {
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (visited[nx][ny])
				continue;

			sum += map[nx][ny];
			visited[nx][ny] = true;
			DFS(nx, ny, depth + 1);
			if (depth == 2)
				DFS(x, y, depth + 1);
			sum -= map[nx][ny];
			visited[nx][ny] = false;
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
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += map[i][j];
			visited[i][j] = true;
			DFS(i, j, 1);
			sum -= map[i][j];
			visited[i][j] = false;
		}
	}
	cout << ans;

	//DFS(백트래킹)으로 ㅓ,ㅏ,ㅗ,ㅜ를 제외한 모든 테트로미노 탐색 가능
	// ㅓ,ㅏ,ㅗ,ㅜ는 depth가 2번째 일때, 3번째 depth인 DFS를 호출하고 난 뒤, 자기 자신을 다시 호출하면 탐색 가능
	return 0;
}