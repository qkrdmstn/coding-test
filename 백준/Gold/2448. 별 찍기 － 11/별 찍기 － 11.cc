#include <iostream>
#include <string>
using namespace std;

int h;
char map[3073][2*3073];

void func(int height, int width, int x, int y)
{
	if (height == 3) {
		map[x][y] = '*';
		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';
		for(int i=-2; i<=2; i++)
			map[x + 2][y + i] = '*';
		return;
	}
	else
	{
		int nxtH = height / 2;
		func(nxtH, 2 * nxtH, x, y);
		func(nxtH, 2 * nxtH, x + nxtH, y + nxtH);
		func(nxtH, 2 * nxtH, x + nxtH, y - nxtH);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < 2*h; j++) {
			map[i][j] = ' ';
		}
	}
	func(h, 2*h, 0, h-1);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < 2 * h; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}