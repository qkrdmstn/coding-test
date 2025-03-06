#include <iostream>
using namespace std;

int k;
int arr[13];
int ans[6];
bool isUsed[13];

void func(int cnt, int start)
{
	if (cnt == 6) {
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	else {
		for (int i = start; i < k; i++) {
			if (isUsed[i])
				continue;
			isUsed[i] = true;
			ans[cnt] = arr[i];
			func(cnt + 1, i + 1);
			isUsed[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> k;
		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
			cin >> arr[i];
		
		func(0, 0);
		cout << '\n';
	}
	return 0;
}