#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	deque<int> dq;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size") {
			cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			cout << dq.empty() << "\n";
		}
		else if (str == "front") {
			if (!dq.empty())
				cout << dq.front() << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "back") {
			if (!dq.empty()) 
				cout << dq.back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;

	//STL deque를 활용한 방식
}