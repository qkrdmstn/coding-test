#include <iostream>
#include <algorithm>
using namespace std;

int n, m, l;
int a[55];

bool solve(int x)
{
	int cnt = 0;
	int pre = 0;
	for (int i = 0; i <= n; i++) {
		int dist = a[i] - pre;

		if (dist >= x) {
			if (dist % x != 0)
				cnt += dist / x;
			else
				cnt += (dist / x) - 1;
		}
		pre = a[i];
	}

	if (cnt > m)
		return true;
	else
		return false;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	a[n] = l;
	int s = 1;
	int e = l;
	while (s < e) {
		int m = (s + e) / 2;
		if (solve(m))
			s = m + 1;
		else
			e = m;
	}
	cout << s;
	return 0;
}