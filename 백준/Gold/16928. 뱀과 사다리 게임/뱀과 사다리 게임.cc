#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void)
{
	int n, m;
	cin >> n >> m;

	vector<int> dist(101, -1);
	vector<int> e(101, -1);
	for (int i = 0; i < n + m; i++)
	{
		int x, y;
		cin >> x >> y;
		e[x] = y;
	}
	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if(cur == 100)
			break;

		for (int i = 1; i <= 6; i++)
		{
			int nxt = cur + i;
			if (nxt > 100) continue;
			if(e[nxt] != -1) nxt = e[nxt];
			if(dist[nxt] != -1) continue;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
	
	cout << dist[100];
	return 0;
}