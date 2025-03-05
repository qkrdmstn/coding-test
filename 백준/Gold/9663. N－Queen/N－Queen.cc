#include <iostream>
using namespace std;

int n, ans;
bool isUsed[16];
bool isUsedRightDown[30];
bool isUsedRightUp[30];

void func(int queenCnt)
{
	if (queenCnt == n) {
		ans++;
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (isUsed[i] || isUsedRightUp[queenCnt + i] || isUsedRightDown[queenCnt - i + n - 1])
				continue;
			isUsed[i] = true;
			isUsedRightUp[queenCnt + i] = true;
			isUsedRightDown[queenCnt - i + n - 1] = true;
			func(queenCnt + 1);
			isUsed[i] = false;
			isUsedRightUp[queenCnt + i] = false;
			isUsedRightDown[queenCnt - i + n - 1] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << ans;
	return 0;
}