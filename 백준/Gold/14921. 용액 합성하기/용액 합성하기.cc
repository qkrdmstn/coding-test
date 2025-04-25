#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 2e9 + 1;
int a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		int l = lower_bound(a, a + n, -a[i]) - a;

		if (l + 1 < n && i != l + 1 && abs(a[i] + a[l + 1]) < abs(ans))
			ans = a[i] + a[l + 1];
		if (l < n && i != l && abs(a[i] + a[l]) < abs(ans))
			ans = a[i] + a[l];
		if (l != 0 && i != l - 1 && abs(a[i] + a[l - 1]) < abs(ans))
			ans = a[i] + a[l - 1];

	}
	cout << ans;
	return 0;
}