#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
queue<long long> q;
vector<long long> v;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i <= 9; i++) {
		q.push(i);
		v.push_back(i);
	}

	while (!q.empty()) {
		long long now = q.front(); q.pop();
		int lastDigit = now % 10;

		for (int i = 0; i < lastDigit; i++) {
			long long next = now * 10 + i;
			q.push(next);
			v.push_back(next);
		}
	}

	if (n >= v.size()) cout << -1;
	else cout << v[n];

	return 0;
}