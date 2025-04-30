#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[10005]; 
int sum;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 0, en = 0;
	sum = a[0];

	for (int st = 0; st < n; st++) {
		while (en < n && sum < m) {
			en++;
			if (en < n) sum += a[en];
		}
		if (en >= n) break;
		if (sum == m)
			ans++;

		sum -= a[st];
	}
	cout << ans;

	return 0;
}