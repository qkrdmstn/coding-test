#include <iostream>
using namespace std;

typedef long long ll;
const int mod = 1'000'000'000;

int n;
ll d[102][10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j != 0) d[i][j] += d[i - 1][j - 1];
			if (j != 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}

	ll ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];
	ans %= mod;
	cout << ans;
	return 0;
}