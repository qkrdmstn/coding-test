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
	
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		bool isValid = true;
		stack<char> s;
		for (auto c : str) {
			if (c == '(')
				s.push(c);
			else if (c == ')') {
				if (s.empty() || s.top() != '(') {
					isValid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) isValid = false;
		if (isValid)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}