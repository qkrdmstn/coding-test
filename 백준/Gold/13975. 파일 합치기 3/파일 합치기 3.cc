#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			int size;
			cin >> size;
			pq.push(size);
		}

		ll ans = 0;
		while (pq.size() > 1) {
			ll min1 = pq.top(); pq.pop();
			ll min2 = pq.top(); pq.pop();
			ans += min1 + min2;
			pq.push(min1 + min2);
		}
		cout << ans << '\n';
	}
	return 0;
}