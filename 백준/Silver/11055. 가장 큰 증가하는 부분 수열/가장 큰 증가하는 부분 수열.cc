#include <iostream>
using namespace std;

int n, ans;
int a[1005];
int dp[1005];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = a[i];
	}

	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + a[i]);
		}
	}
	
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}