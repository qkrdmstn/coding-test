#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
int a[200005];

bool solve(int len)
{
	int idx = 0;
	int cnt = 0;
	while (idx != n) {
		idx = lower_bound(a + idx, a + n, a[idx] + len) - a;
		cnt++;
	}
	return cnt >= c;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	
	int s = 1;
	int e = 1000000000;
	while (s < e) {
		int m = (s + e + 1) / 2;
		if (solve(m))
			s = m;
		else
			e = m - 1;
	}
	cout << s;
	return 0;
}