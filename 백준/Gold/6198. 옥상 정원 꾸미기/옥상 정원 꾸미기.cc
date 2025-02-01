#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	long long ans = 0;
	stack<int> s;

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		long long h;
		cin >> h;

		while (!s.empty() && s.top() <= h)
			s.pop();
		ans += s.size();
		s.push(h);
	}

	cout << ans;
	return 0;
}