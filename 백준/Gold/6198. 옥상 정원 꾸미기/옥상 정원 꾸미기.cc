#include<iostream>
#include<stack>
using namespace std;

int n;
long long sum = 0;
stack<int> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long h;
		cin >> h;
		while (!s.empty() && s.top() <= h) {
			s.pop();
		}
		sum += s.size();
		s.push(h);
	}
	cout << sum;
	return 0;
}