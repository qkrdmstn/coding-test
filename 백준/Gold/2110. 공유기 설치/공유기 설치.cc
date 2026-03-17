#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool check(ll len, vector<ll>& home, int n, int c)
{
	int cnt = 1;
	ll prev = home[0];
	for (int i = 1; i < n; i++)
	{
		if (home[i] - prev >= len)
		{
			cnt++;
			prev = home[i];
		}
	}
	return cnt >= c;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, c;
	cin >> n >> c;
	vector<ll> home(n);
	for (int i = 0; i < n; i++)
		cin >> home[i];
	sort(home.begin(), home.end());


	ll st = 1, ed = home[n-1] - home[0];
	ll ans = 0;
	while (st <= ed)
	{
		ll m = st + (ed-st)/2;
		if (check(m, home, n, c))
		{
			ans = m;
			st = m+1;
		}
		else
			ed = m-1;
	}
	cout << ans;
	return 0;
}