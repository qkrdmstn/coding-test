#include <iostream>
using namespace std;

int n, k;
int state[1'000'005];
int mn = 0x7fffffff, mx = 0;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mn = min(mn, a);
		mx = max(mx, b);

		for (int j = a; j < b; j++)
			state[j]++;
	}

	long long cnt = 0;
	int st = 0, ed = mn;
	for (; st < mx; st++) {
		while (cnt < k && ed < mx) {
			cnt += state[ed];
			ed++;
		}

		if (cnt == k) {
			cout << st << ' ' << ed;
			return 0;
		}
		if (ed >= mx) break;
		cnt -= state[st];
	}
	cout << 0 << ' ' << 0;
	return 0;
}