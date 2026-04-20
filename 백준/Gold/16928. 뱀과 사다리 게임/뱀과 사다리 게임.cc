#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int board[105];

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n + m; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a] = b;
	}

	queue<int> q;
	vector<int> dist(101, -1);

	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == 100)
		{
			cout << dist[cur];
			return 0;
		}

		for (int diff = 1; diff <= 6; diff++)
		{
			int nxt = cur + diff;
			if (nxt > 100) continue;
			if (dist[nxt] >= 0) continue;

			dist[nxt] = dist[cur] + 1;
			if (board[nxt] != 0)
			{
				int nnxt = board[nxt];
				if (dist[nnxt] >= 0) continue;
				dist[nnxt] = dist[cur] + 1;
				q.push(nnxt);
			}
			else
				q.push(nxt);
		}
	}
	cout << -1;
	return 0;
}