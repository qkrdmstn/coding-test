#include <iostream>
#include <string>
using namespace std;

int n;
string map[65];

bool IsOneColor(int size, int startX, int startY)
{
	char curColor = map[startX][startY];
	for (int i = startX; i < startX + size; i++) {
		for (int j = startY; j < startY + size; j++) {
			if (curColor != map[i][j])
				return false;
		}
	}
	return true;
}

void PaperCount(int size, int startX, int startY)
{
	if (IsOneColor(size, startX, startY)) {
		cout<<map[startX][startY];
	}
	else
	{
		cout << '(';
		int nxtSize = size / 2;
		PaperCount(nxtSize, startX, startY);
		PaperCount(nxtSize, startX, startY + nxtSize);
		PaperCount(nxtSize, startX + nxtSize, startY);
		PaperCount(nxtSize, startX + nxtSize, startY + nxtSize);
		cout << ')';
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	PaperCount(n, 0, 0);
	return 0;
}