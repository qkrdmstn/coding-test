#include <iostream>
#include <deque>
#include <string>
using namespace std;

int t;
deque<int> dq;
bool isFront = true;

void parse(string e)
{
	int num = 0;
	for (int i = 1; i < e.length() - 1; i++) {
		if (e[i] == ',') {
			dq.push_back(num);
			num = 0;
		}
		else
			num = num * 10 + (e[i] - '0');
	}
	if (num != 0)
		dq.push_back(num);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		dq.clear();
		isFront = true;
		bool error = false;

		int n;
		cin >> n;
		string e;
		cin >> e;
		parse(e);

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'R')
				isFront = !isFront;
			else if (str[j] == 'D') {
				if (dq.empty() || n == 0) {
					error = true;
					break;
				}
				else if (isFront)
					dq.pop_front();
				else if (!isFront)
					dq.pop_back();
			}
		}

		if (error)
			cout << "error\n";
		else {
			cout << '[';
			if (isFront) {
				for (int k = 0; k < dq.size(); k++) {
					cout << dq[k];
					if (k + 1 != dq.size())
						cout << ',';
				}
			}
			else {
				for (int k = dq.size() - 1; k >= 0; k--) {
					cout << dq[k];
					if (k != 0)
						cout << ',';
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}