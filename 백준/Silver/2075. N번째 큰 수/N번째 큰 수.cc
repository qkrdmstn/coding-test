#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n * n; i++)
	{
		int num;
		cin >> num;
		pq.push(num);

		while(pq.size() > n) pq.pop();
	}
	cout << pq.top();
}