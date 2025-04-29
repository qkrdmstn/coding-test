#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
int a[4005], b[4005], c[4005], d[4005];
vector<ll> sumAB, sumCD;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sumAB.push_back(a[i] + b[j]);
			sumCD.push_back(c[i] + d[j]);
		}
	}

	sort(sumCD.begin(), sumCD.end());

	ll ans = 0;
	for (int i = 0; i < sumAB.size(); i++)
	{
		int l = lower_bound(sumCD.begin(), sumCD.end(), -sumAB[i]) - sumCD.begin();
		int u = upper_bound(sumCD.begin(), sumCD.end(), -sumAB[i]) - sumCD.begin();
		ans += u - l;
	}

	cout << ans;
	return 0;
}