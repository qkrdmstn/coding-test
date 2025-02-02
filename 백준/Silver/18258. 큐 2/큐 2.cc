#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	queue<int> q;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (str == "pop") {
			if (q.size() != 0) {
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size")
			cout << q.size() << "\n";
		else if (str == "empty")
			cout << q.empty() << "\n";
		else if (str == "front") {
			if (q.size() != 0)
				cout << q.front() << "\n";
			else
				cout << "-1\n";
		}
		else if (str == "back") {
			if (q.size() != 0)
				cout << q.back() << "\n";
			else
				cout << "-1\n";
		}
	}

	return 0;
	//STL queue를 이용한 풀이
}