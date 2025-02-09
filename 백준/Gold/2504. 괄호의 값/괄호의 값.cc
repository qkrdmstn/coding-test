#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
stack<char> s;
int sum = 0;
int num = 1;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			num *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[') {
			num *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			s.pop();
			if(str[i - 1] == '(')
				sum += num;
			num /= 2;
		}		
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			s.pop();
			if (str[i - 1] == '[')
				sum += num;
			num /= 3;
		}
	}
	if (s.empty())
		cout << sum;
	else
		cout << 0;
	return 0;
}