#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	queue<int> q;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int i = 0;
	while (q.size() != 1) {
		if (i % 2 == 1)
			q.push(q.front());
		q.pop();
		i++;
	}
	cout << q.front();
	return 0;
}