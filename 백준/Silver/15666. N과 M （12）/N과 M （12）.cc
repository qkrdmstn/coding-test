#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void func(int cnt, int start)
{
	if (cnt == m) {
		for (int i = 0; i < cnt; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	else {
		int tmp = 0;
		for (int i = start; i < n; i++) {
			if ( tmp == arr[i])
				continue;
			ans[cnt] = arr[i];
			tmp = ans[cnt];
			func(cnt + 1, i);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	func(0, 0);
	return 0;
}