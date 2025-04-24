#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m;
ll l[1000005];

bool solve(int h)
{
	ll totalLen = 0;
	for (int i = 0; i < n; i++) {
		if(l[i] > h)
			totalLen += l[i] - h;
	}
	
	if (totalLen >= m)
		return true;
	else
		return false;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> l[i];

	ll s = 0;
	ll e = 1000000000;
	while (s < e) {
		ll mid = (s + e + 1) / 2;
		if (solve(mid))
			s = mid;
		else
			e = mid - 1;
	}
	cout << s;
	return 0;
}