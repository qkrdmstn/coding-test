#include <iostream>
#include <vector>
using namespace std;

int n, x, y, d, g;
int board[105][105];
int cnt = 0;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> x >> y >> d >> g;

		vector<int> v;
		v.push_back(d % 4);
		board[y][x] = 1;

		while (g--) {
			int size = v.size();
			for (int i = size - 1; i >= 0; i--)
				v.push_back((v[i] + 1) % 4);
		}

		for (int i = 0; i < v.size(); i++) {
			int dir = v[i];
			if (dir == 0) x++;
			else if (dir == 1) y--;
			else if (dir == 2) x--;
			else if (dir == 3)y++;
			board[y][x] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!board[i][j]) continue;
			if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}