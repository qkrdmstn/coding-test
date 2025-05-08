#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n, m, k;
string board[11];
unordered_map<string, int> cnt;
int dx[8] = { -1,-1,-1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void dfs(int i, int j, string s)
{
	cnt[s]++;
	if (s.size() == 5) return;
	for (int dir = 0; dir < 8; dir++) {
		int nx = (i + dx[dir] + n) % n;
		int ny = (j + dy[dir] + m) % m;
		dfs(nx, ny, s + board[nx][ny]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(i, j, string(1, board[i][j]));
		}
	}

	for (int i = 0; i < k; i++) {
		string target;
		cin >> target;

		cout << cnt[target] << '\n';
	}
	return 0;
}