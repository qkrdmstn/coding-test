#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			pq.push(x);
			if ((int)pq.size() > n) pq.pop();
		}
	}
	cout << pq.top();
	return 0;
}