#include <iostream>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

#define X first
#define Y second

int n, k;
multiset<int> bag;
pair<int, int> jewel[300003]; // {가격, 무게}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> jewel[i].Y >> jewel[i].X;
	}
	sort(jewel, jewel + n);

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.insert(c);
	}

	long long ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int m, v;
		tie(v, m) = jewel[i];

		auto iter = bag.lower_bound(m);
		if (iter == bag.end()) continue;
		ans += v;
		bag.erase(iter);
	}
	cout << ans;
	return 0;
}