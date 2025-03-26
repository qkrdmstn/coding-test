#include <iostream>
using namespace std;

int n, m;
bool isUsed[9];
int arr[8];

void func(int cnt)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (isUsed[i]) continue;
			isUsed[i] = true;
			arr[cnt] = i;
			func(cnt + 1);
			isUsed[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	func(0);
	return 0;
}