#include<iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	stack<char> s;
	int num = 1;
	int ans = 0;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			num *= 2;
		}
		else if (str[i] == '[') {
			s.push(str[i]);
			num *= 3;
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << "0";
				return 0;
			}
			s.pop();
			if(str[i-1] == '(')
				ans += num;
			num /= 2;
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << "0";
				return 0;
			}
			s.pop();
			if (str[i - 1] == '[')
				ans += num;
			num /= 3;
		}
	}

	if (!s.empty()) 
		cout << "0";
	else 
		cout << ans;

	return 0;
}