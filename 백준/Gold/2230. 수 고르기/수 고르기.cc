#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100'005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	int ans = 2'000'000'001;
	for (int i = 0; i < n; i++) {
		int idx1 = lower_bound(a, a + n, a[i] + m) - a;
		int idx2 = lower_bound(a, a + n, a[i] - m) - a;

		if (idx1 < n && abs(a[i] - a[idx1]) >= m && abs(ans) > abs(a[i] - a[idx1]))
			ans = a[i] - a[idx1];
		if (idx2 < n && abs(a[i] - a[idx2]) >= m && abs(ans) > abs(a[i] - a[idx2]))
			ans = a[i] - a[idx2];
	}
	cout << abs(ans);
	return 0;
}