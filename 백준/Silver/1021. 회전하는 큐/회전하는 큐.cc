#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		int index = 0;
		for (int j = 0; j < dq.size(); j++) {
			if (num == dq[j]) {
				index = j;
				break;
			}
		}

		while (dq.front() != num) {
			if (index - 1 < dq.size() / 2) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cnt++;
		}
		dq.pop_front();
	}
	cout << cnt;
	return 0;
}