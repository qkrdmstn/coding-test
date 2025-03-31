#include <iostream>
using namespace std;

int n;
//d[i]: i번째 항으로 끝나는 연속합 중 최대
int d[100010];
int arr[100010];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = max(0, d[i - 1]) + arr[i];
	}

	int ans = d[1];
	for (int i = 2; i <= n; i++) {
		ans = max(d[i], ans);
	}
	cout << ans;
	return 0;
}