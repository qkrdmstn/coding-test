#include <iostream>
using namespace std;

int n, m, k;
int r, c;
int laptop[41][41];
int sticker[11][11];

bool Pastable(int x, int y)
{
	for(int i=0; i<r; i++){
		for (int j = 0; j < c; j++) {
			if (laptop[x + i][y + j] == 1 && sticker[i][j] == 1)
				return false;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if(sticker[i][j] == 1)
				laptop[x + i][y + j] = 1;
		}
	}
	return true;
}

void Rotate()
{
	int temp[11][11];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = sticker[i][j];
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			sticker[i][j] = temp[r - 1 - j][i];
		}
	}

	int t = r;
	r = c;
	c = t;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cin >> sticker[i][j];
		}

		for (int rot = 0; rot < 4; rot++) {
			bool flag = false;
			for (int i = 0; i <= n - r; i++) {
				if (flag) break;
				for (int j = 0; j <= m - c; j++) {
					if (Pastable(i, j)) {
						flag = true;
						break;
					}
				}
			}
			if (flag)
				break;
			Rotate();
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (laptop[i][j])
				cnt++;
		}
	}
	cout << cnt;
	return 0;

}