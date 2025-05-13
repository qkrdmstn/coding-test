#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int c1 = pq.top(); pq.pop();
		int c2 = pq.top(); pq.pop();
		ans += c1 + c2;
		pq.push(c1 + c2);
	}
	cout << ans;
	return 0;
}