#include <iostream>
using namespace std;

int n;
int map[130][130];
int cnt[2]; //0: white count, 1: blue count

bool IsOneColor(int size, int startX, int startY)
{
	int curColor = map[startX][startY];
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
	if (size == 1 || IsOneColor(size, startX, startY))
		cnt[map[startX][startY]]++;
	else 
	{
		int nxtSize = size / 2;
		PaperCount(nxtSize, startX, startY);
		PaperCount(nxtSize, startX + nxtSize, startY);
		PaperCount(nxtSize, startX, startY + nxtSize);
		PaperCount(nxtSize, startX + nxtSize, startY + nxtSize);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	PaperCount(n, 0, 0);
	cout << cnt[0] << '\n';
	cout << cnt[1] << '\n';
	return 0;
}