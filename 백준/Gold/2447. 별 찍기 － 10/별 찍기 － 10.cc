#include <iostream>
#include <string>
using namespace std;

int n;
char map[6562][6562];

void func(int size, int x, int y)
{
	if (size == 1) {
		map[x][y] = '*';
		return;
	}
	else
	{
		int nxtSize = size / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					continue;
				func(nxtSize, x + i * nxtSize, y + j * nxtSize);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = ' ';
		}
	}
	func(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}