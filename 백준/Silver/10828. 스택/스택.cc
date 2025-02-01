#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (str == "pop") {
			if (s.empty())
				cout << "-1\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (str == "size")
			cout << s.size() << "\n";
		else if (str == "empty")
			cout << s.empty() << "\n";
		else if (str == "top") {
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << "\n";
		}
	}
	return 0;
}