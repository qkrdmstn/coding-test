#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long long ll;

int n;
ll a[5005];
ll ans[3] = { 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f, 0x7f7f7f7f7f7f };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int l = lower_bound(a, a + n, -a[i] - a[j]) - a;

			for (int k = -3; k <= 3; k++) {
				if (l + k == i || l + k == j) continue;
				if (l + k < 0 || l + k >= n) continue;
				if (abs(ans[0] + ans[1] + ans[2]) > abs(a[i] + a[j] + a[l + k]))
					tie(ans[0], ans[1], ans[2]) = { a[i], a[j], a[l + k] }; // tie를 이용해 값 3개를 한번에 assign.        
			}
		}
	}

	sort(ans, ans + 3);
	for(int i=0; i<3; i++)
		cout << ans[i] << ' ';
	return 0;
}