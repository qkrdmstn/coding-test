#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	unordered_map<int, int> upMap;
	unordered_map<int, int> downMap;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		upMap.insert({ x, y });
	}
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		downMap.insert({ u, v });
	}

	vector<int> dist(101, -1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		if (cur == 100)
			break;
		for (int i = 1; i <= 6; i++)
		{
			int nxt = cur + i;
			if (nxt > 100) continue;
			if (dist[nxt] >= 0) continue;


			dist[nxt] = dist[cur] + 1;

			// 도착 지점에 사다리 또는 뱀이 존재할 경우
			if (upMap.find(nxt) != upMap.end())
			{
				int nnxt = upMap[nxt];
				if (dist[nnxt] >= 0) continue;
				q.push(nnxt);
				dist[nnxt] = dist[cur] + 1;
			}
			else if (downMap.find(nxt) != downMap.end())
			{
				int nnxt = downMap[nxt];
				q.push(nnxt);
				if (dist[nnxt] >= 0) continue;
				dist[nnxt] = dist[cur] + 1;
			}
			else q.push(nxt);
		}
	}
	cout << dist[100];
	return 0;
}