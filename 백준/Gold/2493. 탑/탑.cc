#include<iostream>
#include<stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<pair<int, int>> s;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;

		while (!s.empty() && s.top().first < h) {
			s.pop();
		}
		if (s.empty())
			cout << "0 ";
		else
			cout << s.top().second << " ";
		s.push({ h,i });
	}

	return 0;
}