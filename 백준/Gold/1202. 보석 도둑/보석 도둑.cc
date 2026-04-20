#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> jwel(n);
	multiset<int>bag;
	for (int i = 0; i < n; i++)
		cin >> jwel[i].second >> jwel[i].first;
	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		bag.insert(c);
	}

	sort(jwel.begin(), jwel.end(), greater<pair<int, int>>());

	long long ans = 0;
	int getCnt = 0;
	for (auto j : jwel)
	{
		int m, v;
		tie(v, m) = j;
		auto lower = bag.lower_bound(m);
		if (lower != bag.end())
		{
			getCnt++;
			ans += v;
			bag.erase(lower);
		}
		if(getCnt >= k) break;
	}
	cout << ans;
	return 0;
}