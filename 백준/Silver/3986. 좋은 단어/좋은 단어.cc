#include<iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		stack<char> s;
		for (auto c : str) {
			if (!s.empty() && s.top() == c)
				s.pop();
			else
				s.push(c);
		}
		if (s.empty())
			cnt++;
	}

	cout << cnt;
	return 0;
}