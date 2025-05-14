#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<unsigned int> maxHeap;
vector<vector<unsigned int>> v(200'004);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int dl, cup;
		cin >> dl >> cup;
		v[dl].push_back(cup);
	}

	unsigned int ans = 0;
	for (int i = n; i >= 1; i--) {
		for (int cup : v[i])
			maxHeap.push(cup);

		if (maxHeap.empty()) continue;
		ans += maxHeap.top();
		maxHeap.pop();
	}
	cout << ans;
	/*	
	1 10
	2 20
	2 30
	일 때, 20 + 10 이 아닌 20 + 30을 하는 것이 최적이기 때문에
	날짜를 거꾸로 세서, 컵 라면을 가장 많이 주는 것을 선택해야 함
	*/
	return 0;
}