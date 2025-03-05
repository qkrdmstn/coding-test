#include <iostream>
#include <string>
using namespace std;

int n, w;

pair<int, int> func(int size, int walk)
{
	if (size == 2) {
		switch (walk) {
		case 1:
			return { 1,1 };
		case 2:
			return { 1,2 };
		case 3:
			return { 2,2 };
		case 4:
			return { 2,1 };
		}
	}

	int nxtSize = size / 2;
	int s = nxtSize * nxtSize;
	if (walk <= s) {
		pair<int, int> pos = func(nxtSize, walk);
		return { pos.second, pos.first };
	}
	else if (walk <= 2 * s) {
		pair<int, int> pos = func(nxtSize, walk - s);
		return { pos.first, pos.second + nxtSize };
	}
	else if (walk <= 3 * s) {
		pair<int, int> pos = func(nxtSize, walk - 2*s);
		return { pos.first + nxtSize, pos.second + nxtSize };
	}
	else {
		pair<int, int> pos = func(nxtSize, walk - 3*s);
		return { size - pos.second + 1, nxtSize - pos.first + 1};
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w;
	pair<int, int> ans = func(n, w);

	cout << ans.first << ' ' << ans.second;
	return 0;
}