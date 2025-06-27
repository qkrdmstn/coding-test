#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n, k;
vector<int> v;
ll st = 0, ed = 0;

ll func(int len)
{
	ll cnt = 0;
	for (auto x : v)
		cnt += x / len;
	return cnt;
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int x; cin >> x; 
		v.push_back(x);
		if (x > ed)
			ed = x;
	}

	while (st < ed) {
		ll mid = (st + ed + 1) / 2;
		if (func(mid) >= n) st = mid;
		else ed = mid - 1;
	}
	cout << st;
	return 0;
}