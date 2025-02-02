#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	deque<int> dq;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		
		int idx = 0;
		for (int i = 0; i < dq.size(); i++) {
			if (num == dq[i]) {
				idx = i;
				break;
			}
		}

		while (dq.front() != num) {
		
			if (idx > dq.size() - idx) { //오른쪽 이동
				dq.push_front(dq.back());
				dq.pop_back();
			}
			else { //왼쪽 이동
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cnt++;
		}
		dq.pop_front();
	}
	cout << cnt;
	return 0;
}