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

	int totalStick = 0;
	int curStick = 0;
	int ans = 0;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (i < str.length() - 1 && str[i] == '(' && str[i + 1] == ')') {
			ans += curStick;
			i++;
		}
		else if (str[i] == '(') {
			s.push(str[i]);
			curStick++;
			totalStick++;
		}
		else if (str[i] == ')') {
			s.pop();
			curStick--;
		}
	}
	ans += totalStick;
	cout << ans;
	return 0;
}