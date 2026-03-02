#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[2] = { 1,-1 };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> dist(100001, -1);
	queue<int> q;
	int ans = 0;
	q.push(n);
	dist[n] = 0;

	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == k)
		{
			ans++;
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			int nxt = cur;
			if (i == 2)
				nxt *= 2;
			else
				nxt += dx[i];

			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] == -1 || dist[nxt] == dist[cur] + 1)
			{
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
	}

	cout << dist[k] << "\n";
	cout << ans;
	return 0;
}