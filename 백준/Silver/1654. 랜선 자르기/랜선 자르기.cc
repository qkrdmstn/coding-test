#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll CutLAN(ll len, vector<ll>& arr)
{
	ll sum = 0;
	for(auto &a: arr)
		sum += a/len;
	return sum;
}

int main(void)
{
	int k, n;
	cin >> k >> n;
	
	ll s = 1;
	ll e = 0;
	vector<ll> arr(k);
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		e = max(e, arr[i]);
	}

	ll ans = 0;
	while (s <= e)
	{
		ll m = s + (e-s)/2;
		if (CutLAN(m, arr) >= n)
		{
			ans = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	cout << ans;
	return 0;
}
