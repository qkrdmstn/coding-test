#include <iostream>
#include <algorithm>
using namespace std;

int n, s, sum;
int ans = 0x7fffffff;
int a[100'005];

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sum = a[0];
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && sum < s) {
			en++;
			if (en < n) sum += a[en];
		}
		if (en >= n)
			break;
		ans = min(ans, en - st + 1);
		sum -= a[st];
	}

	if (ans == 0x7fffffff) ans = 0;
	cout << ans;
	return 0;
}