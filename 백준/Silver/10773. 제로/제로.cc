#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	stack<int> s;

	cin >> k;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		if (n)
			s.push(n);
		else
			s.pop();
	}

	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}

	cout << sum;
	return 0;
}