#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[2] = {1, -1};
int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	vector<int> dist(100001, -1);

	q.push(n);
	dist[n] = 0;
	int ans = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == k)
			ans++;
		if(dist[k] != -1 && dist[k] < dist[cur]) break;
		for (int i = 0; i < 3; i++)
		{
			int nxt = cur;
			if(i == 2)
				nxt *= 2;
			else
				nxt += dx[i];

			if(nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] == -1 || dist[nxt] == dist[cur] + 1)
			{
				q.push(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
	}

	cout << dist[k] << "\n" << ans;
	return 0;
}