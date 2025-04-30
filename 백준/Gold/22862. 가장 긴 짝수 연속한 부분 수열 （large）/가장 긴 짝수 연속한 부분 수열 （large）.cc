#include <iostream>
using namespace std;

int n, k;
int a[1'000'005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	int en = 0, cnt = 0, ans = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && (cnt < k || a[en] % 2 == 0)) {
			if (a[en] % 2 == 1)
				cnt++;
			en++;
		}
		ans = max(ans, en - st - cnt);
		if (a[st] % 2 == 1) cnt--;
	}
	cout << ans;
	return 0;
}