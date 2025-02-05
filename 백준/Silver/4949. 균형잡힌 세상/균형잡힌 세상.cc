#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string str;
		getline(cin, str);

		if (str == ".")
			break;

		stack<char> s;
		int j = 0;
		bool flag = true;
		while (str[j] != '.') {
			if (str[j] == '(' || str[j] == '[')
				s.push(str[j]);
			else if (str[j] == ')') {
				if (s.empty() || s.top() != '(') {
					flag = false;
					break;
				}
				s.pop();
			}
			else if (str[j] == ']') {
				if (s.empty() || s.top() != '[') {
					flag = false;
					break;
				}
				s.pop();
			}
			j++;
		}
		if (!s.empty()) flag = false;
		if (flag) cout << "yes\n";
		else cout << "no\n";
	}
}